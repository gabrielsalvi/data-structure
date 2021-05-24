/*
 Este é um esqueleto que deve ser utilizado como base para implementação da Agenda:
  - As funções não têm os parâmetros definidos e os parâmetros, caso necessários, devem ser incluídos.
  - Caso seja necessário novas funções podem ser incluídas
  - Devem ser respeitados os nomes dados para o métodos e estruturas, porém novas estruturas e funções podem ser criados, caso julgue necessário
  - Faça os includes necessários
  - A organização das funções fica a critério do programador
  - Códigos não indentados sofrerão duras penalidades
  - Não serão toleradas variáveis globais
  - Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT 10 // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct
{
     int day;
     int month;
     int year;
} Date;

// Estrutura que contém os campos dos registros da agenda
struct MREC
{
     char name[30];
     Date birth;
     char email[40];
     char phone[15];
     struct MREC *next;
     struct MREC *prev;
};

// Tipo criado para instanciar variáveis do tipo agenda
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

     printf("\nDigite os dados do contato: \n");

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

     printf("\nOpa! Já existe um contato com esse email cadastrado na agenda. Abortando inserção!\n");
     
     return NULL;
}

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
     int op;

     printf("\nMenu:\n\t(1) Inserir Contato;\n\t(2) Inserir Contato Posicionado;\n\t(3) Deletar Contato;\n");
     printf("\t(4) Atualizar Contato;\n\t(5) Consultar Contato;\n\t(6) Ver Contatos;\n\t(10) Sair;\n");

     printf("\nOpcao: ");
     scanf("%d", &op);

     return op;
}

// Permite o cadastro de um contato
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
}

// deve ser passado pelo menos o email
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
}

// Permite excluir um contato da agenda baseado no email
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

     free(contact);
     printf("\nO contato de email '%s' foi excluído com sucesso!\n", email);
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts(Contact *contact)
{
     for (Contact *aux = contact; aux != NULL; aux = aux->next)
     {
          printContact(aux);
     }
}

// Permite consultar um contato da agenda por nome
void queryContact(Contact *contact, char *name)
{
     int i = 0;

     for (Contact *aux = contact; aux != NULL; aux = aux->next)
     {
          if (strcmp(aux->name, name) == 0)
          {
               i = i + 1;
               printContact(aux);
          }
     }

     if (i == 0)
     {
          printf("\nNenhum contato encontrado com esse nome!\n");
     }
}

// Permite a atualização dos dados de um contato da agenda
void upContact(ContactsList *clist, char *email)
{
     Contact *contact = getContactByEmail(clist->head, email);

     if (contact == NULL)
     {
          printf("\nNão há nenhum contato cadastrado com esse email!\n");
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

          printf("\nVocê deseja alterar mais algum campo desse contato? -> (1) Sim; (2) Não : ");
          scanf("%d", &op);

          if (op == 2)
          {
               printf("\nContato com as alterações: \n");
               printf("\t-> %s, %d/%d/%d, %s, %s\n", name, birth.day, birth.month, birth.year, contact->email, phone);

               printf("\nVocê deseja salvar as alterações feitas? -> (1) Sim; (2) Não : ");
               scanf("%d", &op);

               if (op == 1)
               {
                    strcpy(contact->name, name);
                    strcpy(contact->phone, phone);
                    contact->birth = birth;

                    printf("\nContato atualizado com sucesso!\n");
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

// Programa principal
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

     freeMem(&clist); // liberar toda a memória alocada
     printf("\nPrograma Finalizada!\n");

     return 0;
}
