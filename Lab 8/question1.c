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
        printf("%d\n",smallest);
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
        return -1;
    }
    return stack[top/2];
}

int main()
{
    int stack[10];
    int choice;
    do
    {
        printf("Choose one of the folowing operations\n");
        printf("1. Push On to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Peek Lowest Element\n");
        printf("4. Peek Highest Element\n");
        printf("5. Peek Middle Element\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        int n;
    switch (choice)
    {
    case 1:
        printf("Give data: ");
        scanf("%d",&n);
        push(n);
        break;
    case 2:
        pop();
        break;
    case 3:
        printf("The lowest number in stack is: %d\n",peek_lowest_element());
        break;
    case 4:
        printf("The highest number in stack is: %d\n",peek_highest_element());
        break;
    case 5:
        printf("The middle number in stack is: %d\n",peek_middle_element());
        break;
    case 6:
        printf("Exiting...");
        break;
    default:
        printf("Give valid option\n");
        break;
    }
    } while(choice!=6);    
    display();
    return 0;

}