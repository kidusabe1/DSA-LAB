#include <stdio.h>
#include <stdlib.h>
#define N 10

int Q[N];
int r=-1,f=-1;
void enqueue_back(int data)
{
    if((r+1)%N==f)
    {
        printf("OVERFLOW\n");
        return ;
    }
    else if(f==-1 && r==-1)
    {
        f=0;
        r=0;
        Q[r]=data;
    }
    else
    {
        r=(r+1)%N;
        Q[r]=data;
    }
}

void enqueue_front(int data)
{
    if( (f==0 && r==N-1) || f==r+1)
    {
        printf("Overflow\n");
        return ;
    }
    else if(f==-1, r==-1)
    {
        f=0;
        r=0;
    }

    else{
        f--;
    }
    Q[f]=data;
    return ;
}

int dequeue_front()
{
    int temp;
    if(f==-1 && r==-1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }

    else if(f==r)
    {
        int temp=Q[f];
        f=-1;
        r=-1;
        return temp;
    }
    else
    {
        int temp=Q[f];
        f=(f+1)%N;
        return temp;
    }
}

int dequeue_back()
{
    if(r==-1 && f==-1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    int temp=Q[r];
    if(f==r)
    {
        f=-1;
        r=-1;
        return temp;
    }

    else if(r==0)
    {
        r=N-1;
    }
    else
        r--;
    return temp;
}

void displayQ()
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
            printf("%d ",Q[i]);
    }
    else
    {
        for (int i = f; i < N; i++)
            printf("%d ", Q[i]);

        for (int i = 0; i <= r; i++)
            printf("%d ", Q[i]);
    }
}

int main()
{
    for(int i=0;i<N-1;i++)
    {
        enqueue_back(i);
    }
    enqueue_front(56);
    displayQ();
    printf("\n");
    displayQ();
    return 0;
}