#include <stdio.h>
int main()
{
    int n,m,i,j;
    printf("GIve the the number of rows and columns respectively\n");
    scanf("%d%d",&m,&n);
    int arr[m][n];
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
    printf("\n Now displaying the elements\n");
    count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d'th Element= %d \n",count+1,arr[i][j]);
        count++;
        }
    }

    //TRANSPOSE OF A MATRIX
    printf("The original matrix is as follows\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("The transpose of the matrix is as follows\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}