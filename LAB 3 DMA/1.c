#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *ptr;
    ptr=(int*) calloc(5,sizeof(int));
    for(i=0;i<5;i++)
    {
        printf("\nGive value of %d",i+1);
        scanf("%d",(ptr+i));
    }
    for(i=0;i<5;i++)
    {
        printf("\nelement %d is =>%d",i+1,*(ptr+i));
    }
    ptr=realloc(ptr,10*sizeof(int));
    printf("\nAfter reallocation the values are");
    for(i=0;i<10;i++)
    {
        printf("\nelement %d is =>%d",i+1,*(ptr+i));
    }
    return 0;
}