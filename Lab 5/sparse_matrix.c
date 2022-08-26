#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sets=0,k=1;
    int arr[5][10]={
        {0,0,0,0,1,4,0,0,0,0},
        {0,0,0,0,0,0,45,0,0,0},
        {0,0,6,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,4,0},
        {0,0,0,0,2,0,0,0,4,0},
    };

    //Count the number of sets
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]!=0)
                sets++;
        }
    }
    //create a sparse matrix of row= original row+1, column=3
    // in row major form
    int arr_sparse[sets+1][3];
    arr_sparse[0][0]=5;
    arr_sparse[0][1]=10;
    arr_sparse[0][2]=sets;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]!=0)
            {
                arr_sparse[k][0]=i;
                arr_sparse[k][1]=j;
                arr_sparse[k][2]=arr[i][j];
                k++;
            }
        }
    }
    //create a sparse matrix of row= 3, column= original rows+1
    // in column major form
    k=1;
    int arr_sparse_col[3][sets+1];
    arr_sparse_col[0][0]=5;
    arr_sparse_col[1][0]=10;
    arr_sparse_col[2][0]=sets;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]!=0)
            {
                arr_sparse_col[0][k]=i;
                arr_sparse_col[1][k]=j;
                arr_sparse_col[2][k]=arr[i][j];
                k++;
            }
        }
    }
    
    printf("The original matrix is as follows\n");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    printf("The row major sparse matrix is as follows\n");
    for(int i=0;i<sets+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",arr_sparse[i][j]);
        }
        printf("\n");
    }

    printf("The column major sparse matrix is as follows\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<sets+1;j++)
        {
            printf("%d ",arr_sparse_col[i][j]);
        }
        printf("\n");
    }
    return 0;
}