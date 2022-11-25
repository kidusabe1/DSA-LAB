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

void sort_stack()
{
    int temp;
    while(top!=-1)
    {
        temp=pop();
        if(top1==-1)
            push1(temp);
        else
        {
            if(temp>=stack1[top1])
            {
                push1(temp);
            }
            else
            {
                while(temp<stack1[top1] && top1!=-1)
                {
                    push(pop1());
                }
                push1(temp);
            }
        }
    }
    while(top1!=-1)
    {
        push(pop1());
    }
}

int main()
{
    push(97);
    push(2);
    push(34);
    push(4);
    display();
    printf("\n");
    sort_stack();
    display();
}   