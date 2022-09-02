//Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
//a) Find the number of nonzero elements in A
//b) Find the sum of the elements above the leading diagonal.
//c) Display the elements below the minor diagonal.
//d) Find the product of the diagonal elements.

#include <stdio.h>
#include <stdlib.h>
int non_zero_count(int arr[][3],int m)
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

int sum_above_leading_diagonal(int arr[][3],int m)
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

void display_elements_below_minor_diagonal(int arr[][3],int m)
{
    for(int i=0;i<m;i++)
    {
        printf("%d ",arr[i][m-i-1]);
    }
}

int product_diagonal_elements(int arr[][3], int m)
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
    int arr[][3]={
        {1,2,4},
        {0,2,4},
        {0,0,5}
    };
    printf("%d\n",non_zero_count(arr,3));
    printf("%d\n",sum_above_leading_diagonal(arr,3));
    display_elements_below_minor_diagonal(arr,3);
    printf("\n");
    printf("%d\n",product_diagonal_elements(arr,3));
    return 0;
}