#include <stdio.h>
void summation(int *x,int *y, int *z)
{
    int result= *x + *y;

}
int product(int *x,int *y)
{
    int result= *x * (*y);
    return result;
}
int diff(int *x, int *y)
{
    int result= *x - *y;
    return result;
}

int main()
{
    int a=10, b=20;
    int *M=&a,*N=&b;
    
    printf("The sum of the a and b is %d\n",summation(M,N));
    printf("The product of the a and b is %d\n",product(M,N));
    printf("The difference of the a and b is %d\n",diff(M,N));
    return 0;
}
