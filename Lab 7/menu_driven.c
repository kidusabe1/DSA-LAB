#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

// Creation 

node* head=NULL;
node* new_node;

node* create_single_linked_node()
{
    node* new= (node*) malloc(sizeof(node));
    new->data=0;
    new->next=NULL;
    return new;
}

node* create_single_linked_list()
{
    int choice=1,num;
    node* ptr=head;
    do
    {
        node* new=create_single_linked_node();
        if(head==NULL)
        {
            head=new;
            head->next=NULL;
            printf("Data: ");
            head->data=scanf("%d",&num);
        }            

        else
        {
            ptr->next=new;
            ptr=new;
            printf("Data: ");
            ptr->data=scanf("%d",&num);
        }    
        printf("do you want more nodes?\n press 1 for no and 0 for yes y/n\n");
        scanf("%d",&choice);
    
    } while (choice==1);
    
}

void display_list(node *head)
{
    node* ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}

node* insert_beginning_singly(node* head)
{
    node* new= create_single_linked_node();
    return new;
}

int main()
{
    create_single_linked_list();
    printf("\n");
    display_list(head);
    return 0;
}
