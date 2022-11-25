#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;
node* new_node=NULL;


node* create_node()
{
    new_node=(node*) malloc(sizeof(node));
    return new_node;
}

void add_a_node()
{
    node* ptr=head;
    if(head==NULL)
    {
        head=create_node();
        head->next=NULL;
        printf("\nGive data: ");
        scanf("%d",&head->data);
    }
    else
    {
        while(ptr!=NULL)
        {
            ptr=ptr->next;
        }
        ptr=create_node();
        ptr->next=NULL;
        printf("\nGive data: ");
        scanf("%d",&new_node->data);
    }
}

void insert_at_beginning()
{
    int num;
    node* new= create_node();
    printf("\nGive data: ");
    scanf("%d",&num);
    new->data=num;
    new->next=head;
    head=new;
}

void insert_middle(int num)
{
    node* ptr=head;
    while(ptr->data!=num)
    {
        ptr=ptr->next;
    }
    node* new=create_node();
    new->next=ptr->next;
    printf("\nGive data: ");
    scanf("%d",&num);
    new->data=num;
    ptr->next=new;
}

// You are doing good
