/* 
Retornar o dia que compoe a data. int comparaDatas(Data data1, Data data2), retorna:
    -1 se a data data1 é anterior à data data2;
    1 se a data data1 é posterior à data data2;
    0 se as datas data1 e data2 são iguais. */

#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int extraiDia(Date date) {
    return date.day;
}

int comparaDatas(Date date1, Date date2) {
    
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
    {
        return 0;
    }
    else 
    {
        if (date1.year >= date2.year) 
        {
            if (date1.month >= date2.month)
            {
                if (date1.day > date2.day) 
                {
                    return 1;
                } 
                else if (date1.day < date2.day)
                {
                    return -1;
                }
            }
        }
    }
    
    return 1;
}

int main() {

    Date dataAtual = {15, 03, 2021};

    Date date;
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    printf("Return: %d\n", comparaDatas(dataAtual, date));

    return 0;
}