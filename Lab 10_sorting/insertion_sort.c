#include <stdio.h>

void insertion_sort__wannna_be(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j>=0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }   
}

void INSERTION_SORT(int arr[],int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[]={5,1,6,9,3,7,2,8,3,6};
    INSERTION_SORT(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
}