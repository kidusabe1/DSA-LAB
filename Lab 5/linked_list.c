#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    node *next;
}node;

node *head=NULL;

int main()
{
    node *ptr;
    int num,n=5;
    head=(node*) malloc(sizeof(node)); //Now the head is pointing to the first node
    printf("Enter data: ");
    scanf("%d",&num);
    head->x=num;
    head->next=NULL;
    //We need ptr to point to the most recent node created;
    ptr=head;
    //CREATION
    for(int i=1;i<n;i++)
    {
        ptr->next=(node*) malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d",&num);    
        ptr->x=num;
        ptr->next=NULL;
        ptr=ptr->next;
    }
    //Displaying
    for(int i=0;i<n;i++)
    {
        printf("Node %d: %d",i+1,head->x);
        ptr=head->next;
    }
//wap to reverse a content of dynamic array of n elements
//wap to search an element in a dynamic array of n elements
//wap to sort a dynamic array of n elements
//wap to implement the triplet reprsentation of a sparse matrix using row and column method
}