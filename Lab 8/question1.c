/*HE5.1 WAP to implement a stack which will support three additional operations in addition to push
and pop by modifying LE5.1.
a) peekLowestElement()
//return the lowest element in the stack without removing it from the stack
b) peekHighestElement()
//return the highset element in the stack without removing it from the stack
c) peekMiddleElement()*/

#include <stdio.h>
#include <stdlib.h>

int top=-1;
int size=10;
int stack[10];
void push(int data)
{
    if(top==size-1)
    {
        printf("Overflow\n");
        return ;
    }
    top++;
    stack[top]=data;
}

void pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return;
    }

    top--;
}

void display()
{
    int it=top;
    while(it>=0)
    {
        printf("%d ",stack[it]);
        it--;
    }
}
int peek_lowest_element()
{
    if(top==-1)
    {
        printf("Undeflow");
        return -1;
    }
    int iterator=top;
    int smallest= stack[top];
    while(iterator>=0)
    {
        if(stack[iterator]<smallest)
        {
            smallest=stack[iterator];
            iterator--;
        }
        else
        {
            iterator--;
        }
    }
    return smallest;
}

int peek_highest_element()
{
    if(top==-1)
    {
        printf("Undeflow");
        return -1;
    }
    int iterator=top;
    int largest=stack[top];
    while(iterator>=0)
    {
        if(stack[iterator]>largest)
            largest=stack[iterator];
        iterator--;
    }
    return largest;
}

int peek_middle_element()
{
    if(top==-1)
    {
        printf("Undeflow");
        return -1;` `   
    }
    return stack[top/2];
}

int main()
{
    int stack[10];
    for(int i=0;i<10;i++)
    {
        push(i);
    }
    printf("The lowest number in stack is: %d\n",peek_lowest_element());
    printf("The highest number in stack is: %d\n",peek_highest_element());
    printf("The middle number in stack is: %d\n",peek_middle_element());
    printf("Exiting...");  
    display();
    return 0;

}