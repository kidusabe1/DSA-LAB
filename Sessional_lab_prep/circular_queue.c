#include <stdio.h>
#define N 5

int my_q[N];
int f=-1,r=-1;


void enq(int data)
{
    if((r+1)%N==f)
    {
        printf("Overflow\n");
        return ;
    }
    else if(f==-1)
    {
        f=0; r=0;
    }
    else
    {
        r=(r+1)%N;
    }
    my_q[r]=data;
}

int deq()
{
    if(f==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    int temp=my_q[f];
    if(f==r)
    {
        f=-1; r=-1;
    }
    else
        f=(f+1)%N;
    return temp;
}

void display()  
{  
    int i=f;  
    if(f==-1 && r==-1)  
    {  
        printf("\n Queue is empty..");  
        return ;
    }  
    if(f>r)
    {
        for(int i=f;i<N;i++)
        {
            printf("%d ",my_q[i]);
        }
        for(int i=0;i>r;i++)
        {
            printf("%d ",my_q[i]);
        }
    }
    else
        for(int i=f;i<=r;i++)
            printf("%d ",my_q[i]);
    printf("\n");
} 

int main()
{
    for(int i=0;i<N;i++)
    {
        enq(i);
    }
    display();
    deq();
    display();
    return 0;
}