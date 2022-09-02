#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[20];
    int roll_number;
    char branch[20];
    struct node* link;// THIS IS SELF REFERENCIAL STRUCTURE.
}node;

node* head=NULL, *new_node, *temp;

int main()
{
    int n,count;
    printf("How many students do you have?\n");
    scanf("%d",&n);
    count=n;
    // Creating required number of nodes
    while(n>0)
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
        n--;
    }

    //     CAN WE INPUT OUR DATA WHILE ALSO CREATING THE NODES?
    
    temp=head;
    printf("DISPLAYING THE FETCHED DATA\n");
    // Displaying fetched data
    for(int i=0;i<count;i++)
    {
        printf("\nName of studen: %s",temp->name);
        printf("\nRoll Number: %d",temp->roll_number);
        printf("\nBranch: %s\n\n",temp->branch);
        temp=temp->link;
    }    

    return 0;

}
