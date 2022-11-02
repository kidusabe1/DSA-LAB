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

void display2()
{
    int it=top2;
    while(it>=0)
    {
        printf("%d ",stack2[it]);
        it--;
    }
}

void sort_stack()
{
    int temp;
    while(top1!=-1)
    {
        temp=pop1();
        if(top2==-1)
        {
            push2(temp);
        }
        else
        {
            if(temp>stack2[top2])
            {
                push2(temp);
            }
            else if(temp<stack2[top2])
            {
                while(temp<stack2[top2] && top2>=-1)
                {
                    int temp2=pop2();
                    push1(temp2);
                }
                push2(temp);
            }
            else
            {
                push2(temp);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        push1(pop2());
    }
}

int main()
{
    push1(1);  
    push1(2);
    push1(23);
    push1(0);
    push1(4);
    push1(6);
    push1(11);
    push1(2);
    push1(22);
    push1(1);
    display1();
    printf("\n");
    sort_stack();
    printf("\n");
    display1();
    return 0;
}