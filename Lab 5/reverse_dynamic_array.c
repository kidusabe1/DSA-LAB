//wap to reverse a content of dynamic array of n elements
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *ptr;
    printf("Number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",(ptr+i));
    }
    //Reversing
    int *ptr_reversed=(int*) malloc(n*sizeof(int));
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        *(ptr_reversed+i)=*(ptr+j);
    }
    //Displaying the reversed elements
    printf("The reversed elements are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d, ",*(ptr_reversed+i));
    }
    free(ptr);
    free(ptr_reversed);
    return 0;
}