#include <stdio.h>
#define N 10
int stack[N];
int top=-1;

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
