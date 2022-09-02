//Given an unsorted dynamic array of size n, WAP to find and display 
//the number of elements between two elements a and b (both inclusive). 
//E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output : 4 and the numbers are: 2, 2, 5, 4.

#include <stdio.h>
#include <stdlib.h>

int count_sub_elements(int *brr,int a, int b)
{
    int count=0;
    int size=(sizeof(brr)/sizeof(int));
    for(int i=0;i<size;i++)
    {
        if(brr[i]==a)
        {
            count++;
            while(brr[i]!=b)
            {
                count++;
                i++;
            }
            return count;
        }
    }
}

int main()
{
    int arr[]={1,2,2,3,4,5,6,7,8,9,10};
    printf("%d\n",count_sub_elements(arr,2,10));
    return 0;
}