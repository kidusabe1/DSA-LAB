#include <stdio.h>
int main()
{
    int n,i,m,index,temp;
    int arr[100];
    printf("Give the the number of elements\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Give the number you want to insert and the index respectively\n");
    scanf("%d%d",&n,&index);
    for(i=m+1;i>index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=n;
    printf("Your updated array is as follows\n");
    for(i=0;i<m+1;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}