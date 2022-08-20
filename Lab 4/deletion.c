#include <stdio.h>
int main()
{
    int del,i,m,index[100],count,temp;
    int arr[100];
    printf("Give the number of elements\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Give the number you want to delete: ");
    scanf("%d",&del);
    for(i=0;i<m;i++)
    {
        if(arr[i]==del)
        {
            index[count]=i;
            count++;
        }
    }
    temp=count;
    while(count>=0)
    {
        for(i=index[count];i<m;i++)
        {
            arr[i]=arr[i+1];
        }
        count--;
    }

    printf("The Updated list is as follwos\n");
    for(i=0;i<m-temp;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}