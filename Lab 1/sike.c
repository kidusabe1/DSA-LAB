#include <stdio.h>
void operation(int *x,int *y)
{
        static int count;
        if(count==0)
        {
            printf("1st\n");
            *x=*x + *y;
            count++;
        }
        else if(count==1)
        {
            printf("2nd\n");
            *x=(*x) * (*y);
            count++;
        }
        else if(count==2)
        {
            printf("3rd\n");
            *x= *x - *y;
        }
}

int main()
{
    int a=10, b=20,count=0;
    int *M=&a,*N=&b;
    operation(M,N);
    printf("The sum of the a and b is %d\n",*M);
    count++;
    a=10;
    operation(M,N);
    printf("The product of the a and b is %d\n",*M);
    a=10;
    operation(M,N);
    printf("The difference of the a and b is %d\n",*M);
    return 0;
}
