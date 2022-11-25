#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int expo;
    int coef;
    struct node* next;
}node;

node* head=NULL;

node* create_poly()
{
    int n;
    printf("How many terms does your polynomial have: ");
    scanf("%d",&n);
    int i=0;
    while(i<n)
    {
        if(head==NULL)
        {
            head=(node*) malloc(sizeof(node));
            printf("Give coefficient and exponent of term %d ",i+1);
            scanf("%d%d",&head->coef,&head->expo);
            head->next=NULL;
        }
        else
        {
            node* ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=(node*) malloc(sizeof(node));
            ptr=ptr->next;
            ptr->next=NULL;
            printf("Give coefficient and exponent of term %d ",i+1);
            scanf("%d%d",&ptr->coef,&ptr->expo);
        }
        i++;
    }
    return head;
}

void display_poly(node* ptr)
{
    node* ptr1=ptr;
    while(ptr1->next!=NULL)
    {
        printf(" %dx^%d ",ptr1->coef,ptr1->expo);
        ptr1=ptr1->next;
    }
}



void add_poly(node* p1, node* p2,node* sum)
{
    node* i=p1;
    node* j=p2;
    while(i!=NULL && j!=NULL)
    {
        if(i->expo > j->expo)
        {
            sum->coef=i->coef;
            sum->expo=i->expo;
            i=i->next;
        }
        else if(i->expo < j->expo)
        {
            sum->coef=j->coef;
            sum->expo=j->expo;
            j=j->next;   
        }
        else if(i->expo==j->expo)
        {
            int x= ((i->coef) + (j->coef));
            sum->expo=i->expo;
            sum->coef=x;
            i=i->next;
            j=j->next;
        }
        sum->next=(node*)malloc(sizeof(node));
        sum=sum->next;
        sum->next=NULL;
    }

    while(i!=NULL)
    {
        sum->coef=i->coef;
        sum->expo=i->expo;
        i=i->next;
        sum->next=(node*)malloc(sizeof(node));
        sum=sum->next;
        sum->next=NULL;
    }
    while(j!=NULL)
    {
        sum->coef=j->coef;
        sum->expo=j->expo;
        j=j->next;   
        sum->next=(node*)malloc(sizeof(node));
        sum=sum->next;
        sum->next=NULL;
    }
    //display_poly(sum);
    //return sum;
}

int main()
{
    node* poly1=create_poly();
    //display_poly(poly1);
    node* poly2=create_poly();
    // display_poly(poly2);
    node* poly3=(node*) malloc(sizeof(node));
    add_poly(poly1,poly2,poly3);
    display_poly(poly3);
    return 0;
}