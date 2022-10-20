#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int row;
    int column;
    int data;
    struct node* next;
}node;

node* new_node1=NULL;
node* head1=NULL;
node* new_node2=NULL;
node* head2=NULL;
node* head3=NULL;

void add_sparse_matrix()
{
    if(head1->row==head2->row)
    {
     //   if()
    }
}