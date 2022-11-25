#include <stdio.h>
#define N 10
int top1=-1;
int top2=-1;
int size=10;
int stack1[N];
int stack2[N];
void push1(int data)
{
    if(top1==N-1)
    {
        printf("Overflow1\n");
        return ;
    }
    top1++;
    stack1[top1]=data;
}

void push2(int data)
{
    if(top2==N-1)
    {
        printf("Overflow2\n");
        return ;
    }
    ++top2;
    stack2[top2]=data;
}

int pop1()
{
    int temp;
    if(top1==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    temp=stack1[top1];
    top1--;
    return temp;
}

int pop2()
{
    int temp;
    if(top2==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    temp=stack2[top2];
    top2--;
    return temp;
}

void display1()
{
    int it=top1;
    while(it>=0)
    {
        printf("%d ",stack1[it]);
        it--;
    }
}

void enqueue(int data)
{
    while(top1!=-1)
    {
        push2(pop1());
    }
    push1(data);
    while(top2!=-1)
    {
        push1(pop2());
    }
}

int dequeue()
{
    int temp=pop1();
    return temp;
}

void display2()
{
    int it=top2;
    while(it>=0)
    {
        printf("%d ",stack2[it]);
        it--;
    }
}

void display_Q()
{
    display1();
}

int main()
{
    enqueue(1);
    enqueue(7);
    enqueue(9);
    dequeue();
    enqueue(0);
    display_Q();
}