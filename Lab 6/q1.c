//Given an unsorted dynamic array of size n, WAP to find and display 
//the number of elements between two elements a and b (both inclusive). 
//E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output : 4 and the numbers are: 2, 2, 5, 4.

#include <stdio.h>
#include <stdlib.h>

int count_sub_elements(int *brr,int a, int b,int size)
{
    int count=0;
    for(int i=0;i<11;i++)
    {
        if(brr[i]>=a && brr[i]<=b)
        {
            count++;
        }
    }
    return count;

}

int main()
{
    int arr[]={1,2,22,-33,-4,5,60,7,8,9,7};
    int a, b;
    printf("Give the value for starting and ending point:\n");
    scanf("%d%d",&a,&b);
    int size=sizeof(arr)/sizeof(int);
    printf("There are %d numbers between %d and %d\n",count_sub_elements(arr,a,b,size),a,b);
    return 0;
}