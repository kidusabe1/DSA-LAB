#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,m,n,key,indexr,indexc,flag=0,largest,temp,times;
    int arr[100][100];
    int brr[100];
    printf("GIve the the number of rows and columns respectively\n");
    scanf("%d%d",&m,&n);
    int count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d'th Element: ",count+1);
            scanf("%d",&arr[i][j]);
            count++;
        }
    }
    printf("Give the number you are looking for\n");
    scanf("%d",&key);
    for(i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==key)
            {
                indexr=i;
                indexc=j;
                flag=1;
            }
        }
    }
    if(flag==1)
        printf("The number %d is found at %d'th row and %d'th column\n",key,indexr+1,indexc+1);
    else
        printf("NOT FOUND!\n");
    
    // FOR SORTING
    printf("GIve the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d",&brr[i]);
    }
    for(times=1;times<=n-1;times++)
    {
        for(i=0;i<=n-times-1;i++)
        {
            if(brr[i]>brr[i+1])
            {
                temp=brr[i];
                brr[i]=brr[i+1];
                brr[i+1]=temp;
            }
        }
    }
    printf("YOUR SORTED ARRAY IS AS FOLLOWS\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",brr[i]);
    }

    return 0;
}