//•	Given a dynamic array, WAP to print the next greater element (NGE) for every element. 
//The next greater element for an element x is the first greater element on the right 
//side of x in array. Elements for which no greater element exist, consider next greater 
//element as -1. E.g. For the input array [2, 5, 3, 9, 7], the next greater elements for each elements are as follows.
//Element	NGE
//2	              5
//5	              9
//3	              9
//9	             -1
//7	             -1
#include <stdio.h>
#include <stdlib.h>
void NGE(int *arr,int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            flag=0;
            if(arr[j]>arr[i])
            {
                printf("%d -> %d\n",arr[i],arr[j]);
                break;
            }
            flag=1;
        }
        if(flag==1)
            printf("%d -> -1\n",arr[i]);
    }
}

int main()
{
    int n=0;
    printf("How many elements? ");
    scanf("%d",&n);
    int *arr= (int*) malloc(n*sizeof(int));
    printf("Give the numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    NGE(arr,n);
}