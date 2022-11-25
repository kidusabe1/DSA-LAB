#include <stdio.h>

void counting_sort(int arr[],int n)
{
    // step one is to get the max element
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    int count[max+1];
    // Initialize the count array with 0
    for(int i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    //store the the repition of each index of count array

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    } 

    // now do a prefix sum on the count array to get the right indexing of each element(but off with 1)

    for(int i=1;i<max+1;i++)
    {
        count[i]+=count[i-1];
    }

    // now create a new array with same size as the original array and expand the updated count array
    // We are starting from the ;ast index so that we keep the stability of the sorted array
    int brr[n];
    for(int i=n-1;i>=0;i--)
    {
        brr[--count[arr[i]]]=arr[i];
    }

    // now copy the new array into the original array
    for(int i=0;i<n;i++)
    {
        arr[i]=brr[i];
    }   
}

int main()
{
    int arr[10]={5,2,7,9,4,2,5,8,4,2};
    counting_sort(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}