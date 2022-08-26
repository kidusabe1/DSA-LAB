//wap to sort a dynamic array of n elements
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,key,index,temp=-1;
    int *ptr;
    printf("Number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",(ptr+i));
    }
    int *ptr_sorted=(int*) malloc(n*sizeof(int));
    for(int times=0;times<n-1;times++)
    {
        for(int j=0;j<n-times;j++)
        {
            if(*(ptr+j)>*(ptr+j+1))
            {
                temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
            }
        }
    }
    //Printing the sorted
    printf("The sorted array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d, ",*(ptr+i));
    }
    return 0;
}