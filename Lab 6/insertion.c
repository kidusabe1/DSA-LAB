#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[20];
    int roll_number;
    char branch[20];
    struct node* link;// THIS IS SELF REFERENCIAL STRUCTURE.
}node;

node* head=NULL, *new_node, *temp;

node* create_new_node_at_beginning(node *head_1)
{   
    node *newer_node= (node*) malloc(sizeof(node));
    printf("Name of student: ");
    scanf("%s",newer_node->name);
    printf("Roll Number: ");
    scanf("%d",&newer_node->roll_number);
    printf("Branch: ");
    scanf("%s",newer_node->branch);
    printf("\n");
    newer_node->link=head;
    head=newer_node;
    free(newer_node);
}

int main()
{
    int n,count;
    char choice;
    // Creating required number of nodes
    do
    {
        if(head==NULL)
        {
            head=(node*)malloc(sizeof(node));
            new_node=head;

            printf("Name of student: ");
            scanf("%s",head->name);
            printf("Roll Number: ");
            scanf("%d",&head->roll_number);
            printf("Branch: ");
            scanf("%s",head->branch);
            head->link=NULL;
            printf("\n");
        }
        else
        {
            new_node->link=(node*) malloc(sizeof(node));
            new_node=new_node->link;

            printf("Name of student: ");
            scanf("%s",new_node->name);
            printf("Roll Number: ");
            scanf("%d",&new_node->roll_number);
            printf("Branch: ");
            scanf("%s",new_node->branch);
            printf("\n");
            new_node->link=NULL;
        }
        printf("Do you want more nodes?\n\t press y for Yes n for No\n");
        scanf(" %c",&choice);
    } while (choice=='y'||choice=='Y');
    
    //     CAN WE INPUT OUR DATA WHILE ALSO CREATING THE NODES?
    // YES WE JUST DID
    temp=head;
    printf("DISPLAYING THE FETCHED DATA\n");
    // Displaying fetched data
    int i=0;
    while(temp->link!=NULL)
    {
        printf("\nName of studen: %s",temp->name);
        printf("\nRoll Number: %d",temp->roll_number);
        printf("\nBranch: %s\n\n",temp->branch);
        temp=temp->link;
        i++;
    }    

    // Inserting New Node in beginning
    /*
    create_new_node_at_beginning(head);
    // After INserting in the beginning
    temp=head;
    printf("DISPLAYING THE FETCHED DATA After INserting in the beginning\n");
    i=0;
    while(temp->link!=NULL)
    {
        printf("\nName of student: %s",temp->name);
        printf("\nRoll Number: %d",temp->roll_number);
        printf("\nBranch: %s\n\n",temp->branch);
        temp=temp->link;
        i++;
    } */
    return 0;

}
