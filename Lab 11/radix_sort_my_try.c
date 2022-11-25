#include <stdio.h>

void counting_sort(int arr[],int n,int place)
{
    int count[10]={0}; // we decided with 10, so that we generalize it
    // Initialize the count array with 0 
    
    //store the the repition of each index of count array

    for(int i=0;i<n;i++)
    {
        count[(arr[i]/place)%10]++;
    } 

    // now do a prefix sum on the count array to get the right indexing of each element(but off with 1)

    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    // now create a new array with same size as the original array and expand the updated count array
    // We are starting from the ;ast index so that we keep the stability of the sorted array
    int brr[n];
    for(int i=n-1;i>=0;i--)
    {
        brr[--count[(arr[i]/place)%10]]=arr[i];
    }

    // now copy the new array into the original array
    for(int i=0;i<n;i++)
    {
        arr[i]=brr[i];
    }   
}

int get_max(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
void radix_sort(int arr[],int n)
{
    // get the maximum number
    int max=get_max(arr,n);

    for(int pos=1;(max/pos)>0;pos*=10) // this for loop does counting sort 'd' times
    // where d is the number of digits in the maximum number and sends in the current
    //position where the counting sort will be done starting from 1->10->100
    {
        counting_sort(arr,n,pos);
    }
}

int main()
{
    int arr[10]={675,65,32,8765,4,24,76,23,6,2};
    radix_sort(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}