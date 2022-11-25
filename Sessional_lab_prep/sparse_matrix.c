#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int row;
    int column;
    int num;
    struct node* next;
}node;

node* head=NULL;
node* add_node(node* sparse,int r, int c, int num)
{
    if(sparse==NULL)
    {
        node* new_node=(node*) malloc(sizeof(node));
        new_node->num=num;
        new_node->next=NULL;
        new_node->row=r;
        new_node->column=c;
        sparse=new_node;
    }
    else
    {
        node* ptr=sparse;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=(node*) malloc(sizeof(node));
        ptr=ptr->next;
        ptr->num=num;
        ptr->next=NULL;
        ptr->row=r;
        ptr->column=c;
    }
    return sparse;
}

void show_matrix(node* sparse)
{
    node* row,*col,*ele;
    row=sparse;
    col=sparse;
    ele=sparse; 
    printf("Row: ");
    while(row!=NULL)
    {
        printf("%d ",row->row);
        row=row->next;
    }
    printf("\nColumn: ");
    while(col!=NULL)
    {
        printf("%d ",col->column);
        col=col->next;
    }
    printf("\nElement: ");
    while(ele!=NULL)
    {
        printf("%d ",ele->num);
        ele=ele->next;
    }
}


node* addition(node* sp1, node* sp2)
{
    node* one,*two,* sum;
    one=sp1;
    two=sp2;
    while(one!=NULL && two!=NULL)
    {
        if(one->row==two->row)
        {
            if(one->column==two->column)
            {
                int temp=one->num+two->num;
                sum=add_node(sum,one->row,one->column,temp);
                one=one->next;
                two=two->next;
            }
            else
            {
                if(one->column>two->column)
                {
                    sum=add_node(sum,one->row,one->column,one->num);
                    one=one->next;
    
                }
                else
                {
                    sum=add_node(sum,two->row,two->column,two->num);
                    two=two->next;
    
                }
            }
        }
        else if(one->row>two->row)
        {
            sum=add_node(sum,one->row,one->column,one->num);
            one=one->next;
        }
        else
        {
            sum=add_node(sum,two->row,two->column,two->num);
            two=two->next;
        }
    }
    while(one!=NULL)
    {
        sum=add_node(sum,one->row,one->column,one->num);
        one=one->next;
    }
    while(two!=NULL)
    {
        sum=add_node(sum,two->row,two->column,two->num);
        two=two->next;
    }
    return sum;
}

int main()
{
   // Assume 4x5 sparse matrix
    int sparseMatric[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    
    int sparseMatric1[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    /* Start with the empty list */
    node* start = NULL;
    node* start1=NULL;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
        {
            printf("hehe\n");
            if (sparseMatric[i][j] != 0)
                start=add_node(start, i, j, sparseMatric[i][j]);
            if (sparseMatric1[i][j] != 0)
                start1=add_node(start1, i, j, sparseMatric1[i][j]);
        }
    node* sum=addition(start,start1);
    
    
    show_matrix(start);
    printf("\n");
    show_matrix(sum);
 
    return 0;
}