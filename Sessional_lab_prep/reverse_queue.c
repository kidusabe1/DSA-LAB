#include <stdio.h>
#define N 5

int my_q[N];
int f=-1,r=-1;


void enq(int data)
{
    if(r==N-1)
    {
        printf("Overflow");
        return ;
    }
    else if(f==-1)
    {
        r=0;
        f=0;
    }
    else
        r++;
    my_q[r]=data;
}

int deq()
{
    if(f==-1)
    {
        printf("Underflow\n");
        return 0;
    }
    int temp=my_q[f];
    if(r==f)
    {
        r=-1; f=-1;
    }
    else
        f++;
    return temp;
}

void display()
{
    if(f==-1)
    {
        printf("Underflow\n");
        return ;
    }
    for(int i=f;i<=r;i++)
    {
        printf("%d ",my_q[i]);
    }
    printf("\n");
}

void reverse_q()
{
    int i=f, j=r;
    while(i<j)
    {
        int temp=my_q[i];
        my_q[i]=my_q[j];
        my_q[j]=temp;
        i++; j--;
    }
}

int main()
{
    enq(1);
    enq(2);
    enq(3);
    display();
    enq(4);
    display();
    deq();
    display();
    reverse_q();
    display();
}