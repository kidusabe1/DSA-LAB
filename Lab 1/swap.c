#include <stdio.h>
void swap_value(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("The value of a and b is %d & %d respectively(swapped by passing just the values)\n",a,b);
}
int swap_address(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}
int main()
{
    int x=12,y=21;
    int *M=&x;
    int *N=&y;
    printf("The values BEFORE swap(pass by value)==> %d & %d\n",x,y);
    printf("\n\n\n\n");
    swap_value(x,y);
    printf("\n\n\n\n");
    printf("The values AFTER swap(pass by value)==> %d & %d\n",x,y);
    printf("##################--------------#######################\n");
    printf("The values BEFORE swap(pass by reference)==> %d & %d\n",x,y);
    printf("\n\n\n\n");
    swap_address(M,N);
    printf("The values AFTER swap(pass by value)==> %d & %d\n",x,y);
    printf("\n\n\n\n");
    return 0;
}