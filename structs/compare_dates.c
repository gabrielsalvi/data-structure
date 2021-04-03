/* The program returns:
        * -1 if the date1 comes before than date2;
        * 1 if the date1 comes after than data2;
        * 0 if both dates are equal */

#include <stdio.h>

typedef struct
{
    int day, month, year;
} Date;

int compareDates(Date date1, Date date2)
{
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
    {
        return 0;
    }
    else
    {
        if (date1.year > date2.year)
        {
            return 1;
        }
        else if (date1.year == date2.year)
        {
            if (date1.month > date2.month)
            {
                return 1;
            }
            else if (date1.month == date2.month)
            {
                if (date1.day > date2.day)
                {
                    return 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    Date d1, d2;

    printf("First date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);

    printf("Second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);

    printf("\ncomapareDates: %d\n", compareDates(d1, d2));

    return 0;
}
