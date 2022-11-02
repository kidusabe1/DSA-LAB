#include <stdio.h>
#include <stdlib.h>
#define N 10
// Considering a circular queue
int Q[N];
int f=-1,r=-1;
void enq(int data)
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

int deq()
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

void displayQ()
{
    int it=f;
    int temp=N;
    
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
    for(int i=0;i<N;i++)
    {
        enq(i);
    }
    displayQ();
    return 0;
}