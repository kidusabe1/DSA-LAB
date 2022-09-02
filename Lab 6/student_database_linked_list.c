#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[20];
    int roll_number;
    char branch[20];
    struct node* link;
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
            head->link=NULL;
        }
        else
        {
            new_node->link=(node*) malloc(sizeof(node));
            new_node=new_node->link;
            new_node->link=NULL;
        }
        n--;
    }
    temp=head;
    // Fetching data from the user and assigning them
    for(int i=0;i<count;i++)
    {
        printf("Name of student %d: ",i+1);
        scanf("%s",&temp->name);
        printf("Roll Number: ");
        scanf("%d",&temp->roll_number);
        printf("Branch: ");
        scanf("%s",&temp->branch);
        temp=temp->link;
        printf("\n");
    }
    
    temp=head;
    printf("DISPLAYING THE FETCHED DATA\n");
    // Displaying fetched data
    for(int i=0;i<count;i++)
    {
        printf("\nName of student %s: ",temp->name);
        printf("\nRoll Number: %d",temp->roll_number);
        printf("\nBranch: %s\n\n",temp->branch);
        temp=temp->link;
    }    

    return 0;

}
