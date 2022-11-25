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

void enq_f(int data)
{
    if((r+1)%N==f)
    {
        printf("Overflow\n");
        return ;
    }
    else if(f==-1, r==-1)
    {
        f=0; r=0;
    }
    else{
        f=(f+N-1)%N;
    }
    my_q[f]=data;
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

int deq_b()
{
    if(f==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    else if(f==r)
    {
        int temp=my_q[r];
        f==-1; r==-1;
        return temp;
    }
    else
    {
        int temp=my_q[r];
        r=(r+N-1)%N;
        return temp;
    }
}

void display()
{
    int it=f;
    if(it==-1 && r==-1)
    {
        printf("UNDERFLOW\n");
        return ;
    }
    if (r >= f)
    {
        for (int i = f; i <= r; i++)
            printf("%d ",my_q[i]);
    }
    else
    {
        for (int i = f; i < N; i++)
            printf("%d ", my_q[i]);

        for (int i = 0; i <= r; i++)
            printf("%d ", my_q[i]);
    }
}

int main()
{
    for(int i=0;i<N-1;i++)
    {
        enq(i);
    }
    enq_f(56);
    display();
    printf("\n");
    display();
}