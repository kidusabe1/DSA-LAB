#include <stdio.h>
void operation(int *x,int *y)
{
    int count=0;
    if(count==0)
        *x+=*y;
        count++;
    if(count==1)
        *x=(*x) *(*y);
        count++;
    if(count==2)
        *x-=*y;
}

int main()
{
    int a=10, b=20,c=0;
    int *M=&a,*N=&b;
    operation(M,N);
    printf("The sum of the a and b is %d\n",*M);
    a=10;
    operation(M,N);
    printf("The product of the a and b is %d\n",*M);
    a=10;
    operation(M,N);
    printf("The difference of the a and b is %d\n",*M);
    return 0;
}
