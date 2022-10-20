//Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
//a) Find the number of nonzero elements in A
//b) Find the sum of the elements above the leading diagonal.
//c) Display the elements below the minor diagonal.
//d) Find the product of the diagonal elements.

#include <stdio.h>
#include <stdlib.h>
int non_zero_count(int **arr,int m)
{
    int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]!=0)
                count++;
        }
    }
    return count;
}

int sum_above_leading_diagonal(int **arr,int m)
{
    int sum=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==j)
            {
                sum+=arr[i][j+1];
            }
        }
    }
    return sum;
}

void display_elements_below_minor_diagonal(int **arr,int m)
{
    for(int i=0;i<m;i++)
    {
        if(i!=m-1)
            printf("%d ",arr[i+1][m-i-1]);
    }
}
// To access the minor elements
void Display_elements_below_minor_diagonal(int **arr,int m)
{
    int k;
    for (int i=m-1,k=0;i>=0;i--,k++)
    {
        for(int j=0;j<m;j++)
        {
            if(j>k)
                printf("%d ",arr[i][j]);
        }
    }
}

int product_diagonal_elements(int **arr, int m)
{
    int product=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==j)
            {
                product*=arr[i][j];
            }
        }
    }
    return product;
}

int main()
{
    int *dARR[3]; // creating 3 pointers that will save the base address of the 3 rows
    for(int i=0;i<3;i++) // a for loop that will allocate memory for the 3 pointers
    {
        dARR[i]=(int*)malloc(3*sizeof(int));
    }

    // taking input for the dynamic matrix
    printf("Give values for 3x3 matrix\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&dARR[i][j]);

    printf("For the matrix below:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",dARR[i][j]);
        }
        printf("\n");
    }

    printf("There are %d non zero elements\n",non_zero_count(dARR,3));
    printf("Sum of elements above the leading diagonal: %d\n",sum_above_leading_diagonal(dARR,3));
    printf("The Elements below the minor diagonal are: ");
    Display_elements_below_minor_diagonal(dARR,3);
    printf("\n");
    printf("The product of the main diagonal elements is: %d\n",product_diagonal_elements(dARR,3));

    return 0;
}