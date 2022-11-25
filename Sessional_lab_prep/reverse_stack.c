#include <stdio.h>
#define N 10
int stack[N];
int stack1[N];
int top=-1;
int top1=-1;
void push(int data)
{
    if(top==N-1)
    {
        printf("Overflow\n");
        return ;
    }
    top++;
    stack[top]=data;
}

int pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    int iter=top;
    if(iter==-1)
    {
        printf("Underflow\n");
        return ;
    }
    while(iter!=-1)
    {
        printf("%d ",stack[iter--]);
    }
}

void push1(int data)
{
    if(top1==N-1)
    {
        printf("Overflow\n");
        return ;
    }
    top1++;
    stack1[top1]=data;
}

int pop1()
{
    if(top1==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    return stack1[top1--];
}

void reverse_stack()
{
    int size=N;
    int temp;
    int iter=top;
    for(int i=0;i<=top;i++)
    {
        temp=pop();
        while(top!=-1)
        {
            push1(pop());
        }
        push(temp);
        while(top1!=-1)
        {
            push(pop1());
        }
    }
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    printf("\n");
    reverse_stack();
    display();
}   