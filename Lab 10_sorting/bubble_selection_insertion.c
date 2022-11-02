#include <stdio.h>


void swap(int arr[],int i1,int i2)
{
    int temp=arr[i1];
    arr[i1]=arr[i2];
    arr[i2]=temp;
}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void bubble_sort(int arr[],int n)
{
    int smallest;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr,j,j+1);
            }
        }
    }
}

void selection_sort(int arr[],int n)
{
    long int smallest=100000,key;
    for(int i=0;i<n-1;i++)
    {
        key=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[key])
            {
                smallest=arr[j];
                key=j;
            }
        }
        if(key!=i)
        {
            swap(arr,key,i);
            print_array(arr,6);
            printf("\n");
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[]={3,1,2,6,5,4};
    //bubble_sort(arr,6);
    print_array(arr,6);
    printf("\n");
    int arr[]={3,1,2,6,5,4};
    selection_sort(arr,6);
    print_array(arr,6);
    printf("\n");
    arr[]={3,1,2,6,5,4};
    insertionSort(arr,6);
    print_array(arr,6);
}