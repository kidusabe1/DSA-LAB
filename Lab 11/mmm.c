#include <stdio.h>

void merge(int arr[],int lb,int middle,int ub)
{
    int i=lb,j=middle+1,k=lb;
    int B[ub-lb];
    while(i<=middle && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            B[k]=arr[i];
            i++;
        }
        if(arr[j]<arr[i])
        {
            B[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=middle)
    {
        B[k++]=arr[i++];
    }
    while(j<=ub)
    {
        B[k++]=arr[j++];
    }
    for(int i=lb;i<=ub;i++)
    {
        arr[i]=B[i];
    }
}

void merge_sort(int arr[],int lb,)