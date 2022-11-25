#include <stdio.h>

int linear_search(int arr[],int key,int n)
{
    int index_found=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
            index_found=i;
    }
    return index_found;
}



int linear_search_recursively(int arr[],int n,int key){

    n--;
    if(n < 0){
        return -122;
    }
    if(arr[n]==key){
        return n;
    }
    return linear_search_recursively(arr,n,key);
}

int searchElement(int arr[], int size, int x) {
     
    size--;
    if (size < 0) {
        return -2;
    }
    if (arr[size] == x) {
        return size;
    } 
    return searchElement(arr, size, x);
 
}

int main()
{
    int arr[]={2,5,2,5,3,67,8};
    int n=linear_search_recursively(arr,7,122);
    //int n=searchElement(arr,7,122);
    printf("\n%d\n",n);
}