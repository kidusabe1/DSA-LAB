#include <stdio.h>

#define N 10
int Q1[N],Q2[N];
int r1=-1,f1=-1;
int r2=-1,f2=-1;
void enqueue_back1(int data)
{
    if((r1+1)%N==f1)
    {
        printf("OVERFLOW\n");
        return ;
    }
    else if(f1==-1 && r1==-1)
    {
        f1=0;
        r1=0;
        Q1[r1]=data;
    }
    else
    {
        r1=(r1+1)%N;
        Q1[r1]=data;
    }
}

int dequeue_front1()
{
    int temp;
    if(f1==-1 && r1==-1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }

    else if(f1==r1)
    {
        int temp=Q1[f1];
        f1=-1;
        r1=-1;
        return temp;
    }
    else
    {
        int temp=Q1[f1];
        f1=(f1+1)%N;
        return temp;
    }
}

void enqueue_back2(int data)
{
    if((r2+1)%N==f2)
    {
        printf("OVERFLOW\n");
        return ;
    }
    else if(f2==-1 && r2==-1)
    {
        f2=0;
        r2=0;
        Q2[r2]=data;
    }
    else
    {
        r2=(r2+1)%N;
        Q2[r2]=data;
    }
}

int dequeue_front2()
{
    int temp;
    if(f2==-1 && r2==-1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }

    else if(f2==r2)
    {
        int temp=Q2[f2];
        f2=-1;
        r2=-1;
        return temp;
    }
    else
    {
        int temp=Q2[f2];
        f2=(f2+1)%N;
        return temp;
    }
}
void displayQ()
{
    int it=f1;
    if(it==-1 && r1==-1)
    {
        printf("UNDERFLOW\n");
        return ;
    }
    if (r1 >= f1)
    {
        for (int i = f1; i <= r1; i++)
            printf("%d ",Q1[i]);
    }
    else
    {
        for (int i = f1; i < N; i++)
            printf("%d ", Q1[i]);

        for (int i = 0; i <= r1; i++)
            printf("%d ", Q1[i]);
    }
}

void push(int x)
{
    enqueue_back2(x);
    while(f1!=-1)
    {
        enqueue_back2(dequeue_front1());
    }
    while(f2!=-1)
    {
    enqueue_back1(dequeue_front2());
    }
}

int pop()
{
    int temp=dequeue_front1();
    return temp;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    push(4);
    displayQ();
    return 0;
}