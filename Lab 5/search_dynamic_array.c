//wap to search an element in a dynamic array of n elements
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,key,index=-1;
    int *ptr;
    printf("Number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",(ptr+i));
    }
    printf("Number you are looking for: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(key==*(ptr+i))
            index=i;
    }
    if(index!=-1)
    {
        printf("The number %d is located at %d index of the array\n",key,index);
    }
    else
        printf("not found\n");
    return 0;
}