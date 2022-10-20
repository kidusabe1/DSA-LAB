/*HE5.1 WAP to implement a stack which will support three additional operations in addition to push
and pop by modifying LE5.1.
a) peekLowestElement()
//return the lowest element in the stack without removing it from the stack
b) peekHighestElement()
//return the highset element in the stack without removing it from the stack
c) peekMiddleElement()*/

#include <stdio.h>
#include <stdlib.h>
#define N 10
int top1=-1;
int stack1[10];

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

void display1()
{
    int it=top1;
    while(it>=0)
    {
        printf("%d ",stack1[it]);
        it--;
    }
}


void transfer(int stack[],int temp,int size)
{
    int s2[size];
    for(int i=0;i<size;i++)
    {
        s2[i]=pop1();
    }
    push1(temp);
    for(int i=size-1;i>=0;i--)
    {
        push1(s2[i]);
    }
}

void reverse_stack(int stack[],int size)
{
    int temp;
    for(int i=0;i<size;i++)
    {
        temp=pop1();
        transfer(stack1,temp,size-i-1);
    }
}
int main()
{
    int choice;
    push1(1);
    push1(2);
    push1(3);
    push1(4);
    display1();
    reverse_stack(stack1,4);
    printf("\n");
    display1();
    return 0;
}