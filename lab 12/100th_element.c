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
    counting_sort(arr,n,100);
}

int main()
{
    int arr[10]={675,965,232,8765,114,3224,32476,23423,3246,322};
    radix_sort(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}