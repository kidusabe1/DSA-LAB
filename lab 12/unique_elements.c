//WAP to sort the unique numbers from the array 
#include <stdio.h>
#include <stdlib.h>
int unique[100];
int k=0;
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
int uniqueEle(int array[], int n){
   int i,j;
   int count = 1;
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         if(array[i] == array[j] && i != j)
         break;
      }
      if(j == n )
      {
         unique[k++]=array[i];
         ++count;
      }
   }
   return -1;
}
int main(){
   int n,i;
   printf("Enter no: of elements : ");
   scanf("%d",&n);
   int array[n];
   printf("enter the array elements : ");
   for(i = 0; i < n; i++){
      scanf("%d",&array[i]);
   }
   uniqueEle(array, n);
   bubble_sort(unique,k);
   print_array(unique,k);
   return 0;
}