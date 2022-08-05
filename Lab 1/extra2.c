#include <stdio.h>
void summation(int *x,int *y)
{
    *x+=*y;
}
void product(int *x,int *y)
{
    *x=(*x) *(*y);
}
void diff(int *x, int *y)
{
    *x-=*y;
}

int main()
{
    int a=10, b=20,c=0;
    int *M=&a,*N=&b;
    summation(M,N);
    printf("The sum of the a and b is %d\n",*M);
    a=10; 
    product(M,N);
    printf("The product of the a and b is %d\n",*M);
    a=10; 
    diff(M,N);
    printf("The difference of the a and b is %d\n",*M);
    return 0;
}
