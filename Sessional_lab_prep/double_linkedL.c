#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;


node* head=NULL;
node* new_node=NULL;

node* create_node()
{
    new_node=(node*) malloc(sizeof(node));
    new_node->data=0;
    new_node->next=NULL;
    new_node->prev=NULL;
}

void add_node()
{
    if(head==NULL)
    {
        head=create_node();
        printf("\nGive data: ");
        scanf("%d",&head->data);
    }
    else
    {
        node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        node* new=create_node();
        new->prev=ptr;
        ptr->next=new;
        printf("\nGive data: ");
        scanf("%d",&ptr->data);
    }
}


void delete_middle(int num)
{
    node* ptr=head;
    while(ptr->next->data!=num)
    {
        ptr=ptr->next;
    }
    node* to_be=ptr->next;
    ptr->next->next->prev=ptr;
    ptr->next=ptr->next->next;
    free(to_be);
}