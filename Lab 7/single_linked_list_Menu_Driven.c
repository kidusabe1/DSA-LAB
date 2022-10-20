#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* new_node;
node* head=NULL;


node* create_node()
{
    node* new=(node*) malloc(sizeof(node));
    new->data=0;
    new->next=NULL;
    return new;
}

void create_and_accept_linked_list()
{
    int choice=1;
    do
    {
        printf("Do you want to provide more data?\nPress 1 for yes and 0 for no: ");
        scanf("%d",&choice);
        if(choice==0)
            break;
        else
        {
            if(head==NULL)
            {
                head=create_node();
                new_node=head;
                printf("\nGive data: ");
                scanf("%d",&head->data);
            }
            else
            {
                new_node->next=create_node();
                new_node=new_node->next;
                printf("\nGive data: ");
                scanf("%d",&new_node->data);                
            }
        }
    } while (choice==1);
}

void display_linked_list(node *head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void insert_beginning()
{
    int num;
    node* new=create_node();
    if(new==NULL)
    {
        printf("OVER FLOW\n");
        return ;
    }    
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
    printf("\nGive data: ");
    scanf("%d",&new->data);
    new->next=ptr->next;
    ptr->next=new;
}

void insert_end()
{
    node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=create_node();
    ptr=ptr->next;
    printf("\nGive Data:");
    scanf("%d",&ptr->data);
}

void delete_beginning()
{
    node* ptr=head->next;
    free(head);
    head=ptr;
    printf("\nFirst node deleted\n");
    display_linked_list(head);
}

void delete_middle(int num)
{
    node* ptr=head;
    while(ptr->next->data!=num)
    {
        ptr=ptr->next;
    }
    node* to_be_deleted=ptr->next;
    ptr->next=ptr->next->next;
    free(to_be_deleted);
    printf("\ndeleted node in the middle\n");
    display_linked_list(head);
}

void delete_end()
{
    node* ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
    printf("\nDeleted last node\n");
    display_linked_list(head);
}

int main()
{
    int choice,num;
    do
    {

        printf("\n\t\t\tSingle List Operations\n");
        printf("Choose your desired option to perform an operation\n");
        printf("1. Create a singly linked list\n2. Insert a node at the beginning\n3. Insert a node in the middle\n4. Insert a node at the end\n");
        printf("5. Delete the first node\n6. Delete a node in the middle\n7. Delete the last node\n8. Display Linked List\n9. Exit");
        printf("\nInput: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create_and_accept_linked_list();
            break;
        case 2:
            insert_beginning();
            break;
        case 3:
            printf("After which data point do you want to add a data\n");
            scanf("%d",&num);
            insert_middle(num);
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_beginning();
            break;
        case 6:
            printf("Which data point do you want to delete?\n");
            scanf("%d",&num);
            delete_middle(num);
            break;
        case 7:
            delete_end();
            break;
        case 8:
            display_linked_list(head);
            break;
        case 9:
            printf("Exiting...");
        default:
            break;
        }
       
    } while (choice!=9);
    return 0;
}

