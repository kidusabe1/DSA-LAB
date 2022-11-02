#include <stdio.h>

int array[]={6,3,7,2,56,3,8,4,3,8};
int sorted_array[10];

void Merge(int low,int middle, int high)
{
    int l1=low;
    int l2=middle+1;
    int i=0;
    static int k=0;
    while(l1<=middle && l2<=high)
    {
        if(array[l1]<=array[l2])
        {
            sorted_array[i++]=array[l1++];
        }
        else
        {
            sorted_array[i++]=array[l2++];
        }
    }
    while(l1<=middle)
    {
        sorted_array[i++]=array[l1++];
    }
    while (l2<=high)
    {
        sorted_array[i++]=array[l2++];
    }
    for(int i=low,k=0;i<=high;i++)
    {
        array[i]=sorted_array[k++];
    }
}

void merge_sort(int low,int high)
{
    int middle;
    if(low<high)
    {
        middle=(low+high)/2;
        merge_sort(low,middle);
        merge_sort(middle+1,high);
        Merge(low,middle,high);
    }
    else
    {
        return ;
    }
}

int main()
{
    printf("Array before merge sort\n");
    for(int i=0;i<10;i++)
        printf("%d ",array[i]);
    merge_sort(0,9);
    printf("\nArray after merge sort\n");
    for(int i=0;i<10;i++)
        printf("%d ",sorted_array[i]);
}