//Write a program to initialize an aray using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("How many elements do u want to provide?\n");
    scanf("%d",&n);
    int*ptr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Give %d'th element: ",i+1);
        scanf("%d",&ptr[i]);
    }
    printf("DISPLAYING UR ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        printf("%d'th element= %d\n",i+1,*(ptr+i));
    }
    return 0;
}
