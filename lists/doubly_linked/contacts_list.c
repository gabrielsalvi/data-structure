#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT 10

typedef struct
{
     int day;
     int month;
     int year;
} Date;

struct MREC
{
     char name[30];
     Date birth;
     char email[40];
     char phone[15];
     struct MREC *next;
     struct MREC *prev;
};

typedef struct MREC Contact;

typedef struct
{
     Contact *head;
     Contact *tail;
} ContactsList;

void initContactsList(ContactsList *clist)
{
     clist->head = NULL;
     clist->tail = NULL;
}

Contact *getContactByEmail(Contact *contact, char email[40])
{
     for (Contact *aux = contact; aux != NULL; aux = aux->next)
     {
          if (strcmp(aux->email, email) == 0)
          {
               return aux;
          }
     }

     return NULL;
}

void printContact(Contact *contact)
{
     printf("\t-> %s, %d/%d/%d, %s, %s\n", contact->name, contact->birth.day, contact->birth.month, contact->birth.year, contact->email, contact->phone);
}

Contact *createContact(ContactsList *clist)
{
     char email[40];

     printf("\nDigite os dados do novo contato: \n");

     printf("\nEmail: ");
     scanf("%s", email);

     if (getContactByEmail(clist->head, email) == NULL)
     {
          Contact *contact = (Contact *)malloc(sizeof(Contact));

          printf("Nome: ");
          scanf("%s", contact->name);

          strcpy(contact->email, email);

          printf("Data de Nascimento: ");
          scanf("%d/%d/%d", &contact->birth.day, &contact->birth.month, &contact->birth.year);

          printf("Telefone: ");
          scanf("%s", contact->phone);

          contact->prev = NULL;
          contact->next = NULL;

          return contact;
     }

     printf("\nOpa! Já existe um contato com o email '%s' cadastrado na agenda. Abortando inserção!\n", email);

     return NULL;
}

int menu()
{
     int op;

     printf("\nMenu:\n\t(1) Inserir Contato;\n\t(2) Inserir Contato Posicionado;\n\t(3) Deletar Contato;\n");
     printf("\t(4) Atualizar Contato;\n\t(5) Consultar Contato;\n\t(6) Ver Contatos;\n\t(10) Sair;\n");

     printf("\nOpcao: ");
     scanf("%d", &op);

     return op;
}

void insContact(ContactsList *clist)
{
     Contact *contact = createContact(clist);

     if (contact == NULL)
     {
          return;
     }

     if (clist->head == NULL)
     {
          clist->head = contact;
          clist->tail = contact;
     }
     else
     {

          clist->tail->next = contact;
          contact->prev = clist->tail;
          clist->tail = contact;
     }

     printf("\nLegal, %s agora faz parte dos seus contatos!\n", contact->name);
}

void insContactAfter(ContactsList *clist, char *email)
{
     Contact *contact = createContact(clist);

     if (contact == NULL)
     {
          return;
     }

     if (clist->head == NULL)
     {
          clist->head = contact;
          clist->tail = contact;
     }
     else
     {
          Contact *previous = getContactByEmail(clist->head, email);

          if (previous)
          {
               if (previous == clist->tail)
               {
                    previous->next = contact;
                    contact->prev = previous;
                    clist->tail = contact;
               }
               else
               {
                    contact->prev = previous;
                    contact->next = previous->next;
                    previous->next->prev = contact;
                    previous->next = contact;
               }
          }
          else
          {
               contact->next = clist->head;
               clist->head->prev = contact;
               clist->head = contact;
          }
     }

     printf("\nLegal, %s agora faz parte dos seus contatos!\n", contact->name);
}

void delContact(ContactsList *clist, char *email)
{
     Contact *contact = getContactByEmail(clist->head, email);

     if (contact == NULL)
     {
          printf("\nNão há nenhum contato cadastrado com o email '%s'!\n", email);
          return;
     }
     if (clist->head == clist->tail)
     {
          initContactsList(clist);
     }
     else if (contact == clist->head)
     {
          clist->head = clist->head->next;
          clist->head->prev = NULL;
     }
     else if (contact == clist->tail)
     {
          clist->tail = clist->tail->prev;
          clist->tail->next = NULL;
     }
     else // quando o contato está no meio da agenda
     {
          contact->prev->next = contact->next;
          contact->next->prev = contact->prev;
     }

     printf("\nO contato de email '%s' foi excluído com sucesso!\n", contact->email);
     free(contact);
}

void listContacts(Contact *contact)
{
     for (Contact *aux = contact; aux != NULL; aux = aux->next)
     {
          printContact(aux);
     }
}

void queryContact(Contact *contact, char *name)
{
     int i = 0;

     for (Contact *aux = contact; aux != NULL; aux = aux->next)
     {
          if (strcmp(aux->name, name) == 0)
          {
               i += 1;
               printContact(aux);
          }
     }

     if (i == 0)
     {
          printf("\nNenhum contato encontrado com o nome '%s'!\n", name);
     }
}

void upContact(ContactsList *clist, char *email)
{
     Contact *contact = getContactByEmail(clist->head, email);

     if (contact == NULL)
     {
          printf("\nNão há nenhum contato cadastrado com o email '%s'!\n", email);
          return;
     }

     printf("\nDados atuais do contato: \n");
     printf("\t-> %s, %d/%d/%d, %s, %s\n", contact->name, contact->birth.day, contact->birth.month, contact->birth.year, contact->email, contact->phone);

     char name[30];
     char phone[15];
     Date birth;

     strcpy(name, contact->name);
     strcpy(phone, contact->phone);
     birth = contact->birth;

     int op = 1;

     while (op != 0)     
     {
          printf("\nQue campo você deseja alterar? \n\t-> (0) Voltar; (1) Nome; (2) Data de Nascimento; (3) Telefone : ");
          scanf("%d", &op);

          switch (op)
          {
          case 0:
               break;

          case 1:
               printf("\nNome: ");
               scanf("%s", name);
               break;

          case 2:
               printf("Data de Nascimento: ");
               scanf("%d/%d/%d", &birth.day, &birth.month, &birth.year);
               break;

          case 3:
               printf("Telefone: ");
               scanf("%s", phone);
               break;
          }

          if (op != 0)
          {
               printf("\nVocê deseja alterar mais algum campo desse contato? -> (1) Sim; (2) Não : ");
               scanf("%d", &op);
          }

          if (op == 2)
          {
               printf("\nContato com as alterações:\n");
               printf("\t-> %s, %d/%d/%d, %s, %s\n", name, birth.day, birth.month, birth.year, contact->email, phone);

               printf("\nVocê deseja salvar as alterações feitas? -> (1) Sim; (2) Não : ");
               scanf("%d", &op);

               if (op == 1)
               {
                    strcpy(contact->name, name);
                    strcpy(contact->phone, phone);
                    contact->birth = birth;

                    printf("\nO contato de email '%s' foi atualizado com sucesso!\n", contact->email);
               }
               else
               {
                    printf("\nAs alterações foram descartadas!\n");
               }

               break;
          }
     }
}

void freeMem(ContactsList *clist)
{
     Contact *delete = NULL;

     while (clist->head)
     {
          delete = clist->head;
          clist->head = clist->head->next;

          free(delete);
     }

     initContactsList(clist);
}

int main()
{
     int op = EXIT + 1;

     ContactsList clist;
     initContactsList(&clist);

     char email[40];
     char name[30];

     while (op != EXIT)
     {
          op = menu();

          switch (op)
          {
          case 1:
               insContact(&clist);
               break;

          case 2:
               printf("\nEmail anterior: ");
               scanf("%s", email);

               insContactAfter(&clist, email);
               break;

          case 3:
               if (clist.head == NULL)
               {
                    printf("\nA agenda está vazia!\n");
                    break;
               }

               printf("\nEmail do Contato: ");
               scanf("%s", email);

               delContact(&clist, email);
               break;

          case 4:
               if (clist.head == NULL)
               {
                    printf("\nA agenda está vazia!\n");
                    break;
               }

               printf("\nEmail do Contato: ");
               scanf("%s", email);

               upContact(&clist, email);
               break;

          case 5:
               if (clist.head == NULL)
               {
                    printf("\nA agenda está vazia!\n");
                    break;
               }

               printf("\nProcurar pelo nome: ");
               scanf("%s", name);

               queryContact(clist.head, name);
               break;

          case 6:
               if (clist.head == NULL)
               {
                    printf("\nA agenda está vazia!\n");
                    break;
               }

               printf("\nLista de Contatos: \n\n");
               printf("\tNome | Data de Nascimento |  Email | Telefone\n");

               listContacts(clist.head);
               break;
          }
     }

     freeMem(&clist);
     printf("\nPrograma Finalizado!\n");

     return 0;
}
