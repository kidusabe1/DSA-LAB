#include <stdio.h>
#include <stdlib.h>

typedef struct year{
    int day;
    int month;
    int year;
}year;

int main()
{
    int flag=0;
    year y_in;
    error:

    printf("PLease give a valid date in DD/MM/YY format\n");
    scanf("%d %d %d",&y_in.day,&y_in.month,&y_in.year);
    if ((y_in.year%4==0 && y_in.year%100!=0) || (y_in.year%400==0))
    {
        printf(" %d is a leap year\n",y_in.year);
        flag=1;
    }
    else
    {
        printf("%d is not a leap year\n", y_in.year);
    }
    if(y_in.month>12)
    {
        printf("INVALID MONTH! give a valid month!\n");
        goto error;     
    }
    if(y_in.month==2 && y_in.day>29 && flag==1)
    {
        printf("INVALID DAY! Give a valida day\n");
        goto error;
    }
    if(y_in.month=2 && y_in.day>28 && flag==0)
    {
        printf("INVALID DAY! Give a valida day\n");
        goto error;
    }
    if((y_in.month== 1 || y_in.month==3 || y_in.month==5 || y_in.month==7 || y_in.month==8 || y_in.month==10 || y_in.month==12) && y_in.day>31)
    {
        printf("INVALID DAY! Give a valida day\n");
        goto error;
    }
    if((y_in.month==4 || y_in.month==6 || y_in.month==9 || y_in.month==11) && y_in.day>30)
    {
        printf("INVALID DAY! Give a valid day\n");
        goto error;
    }

    printf("You have provided the following date %d/%d/%d ",y_in.day,y_in.month,y_in.year);
    return 0;

}