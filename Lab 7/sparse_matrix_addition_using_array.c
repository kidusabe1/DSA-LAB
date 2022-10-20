#include <stdio.h>
#include <stdlib.h>

void sparse_add(int sparse_arr1[][3],int sparse_arr2[][3],int n,int m)
{
    int non_zero= n+m; //max number of non zero elements
    int result[non_zero+1][3];//worst case scenario
    result[0][0]=sparse_arr1[0][0];
    result[0][1]=sparse_arr1[0][1];
    result[0][2]=0;
    int i=1,j=1,k=1;
    while(i<n+1 && j<m+1)
    {
        if(sparse_arr1[i][0]==sparse_arr2[j][0])
        {
            if(sparse_arr1[i][1]==sparse_arr2[j][1])
            {
                result[k][0]=sparse_arr1[i][0];
                result[k][1]=sparse_arr1[i][1];
                result[k][2]= sparse_arr1[i][2]+sparse_arr2[j][2];
                k++;
                i++;
                j++;
            }
            else
            {
                if(sparse_arr1[i][1]<sparse_arr2[j][1])
                {
                    result[k][0]=sparse_arr1[i][0];
                    result[k][1]=sparse_arr1[i][1];
                    result[k][2]=sparse_arr1[i][2];
                    k++; i++; 
                }

                else
                {
                    result[k][0]=sparse_arr2[j][0];
                    result[k][1]=sparse_arr2[j][1];
                    result[k][2]=sparse_arr2[j][2];
                    k++; j++;
                }
            }
        }

        else
        {
            if(sparse_arr1[i][0]<sparse_arr2[j][0])
            {
                result[k][0]=sparse_arr1[i][0];
                result[k][1]=sparse_arr1[i][1];
                result[k][2]=sparse_arr1[i][2];
                k++; i++; 
            }

            else
            {
                result[k][0]=sparse_arr2[j][0];
                result[k][1]=sparse_arr2[j][1];
                result[k][2]=sparse_arr2[j][2];
                k++; j++;
            }
        }
    } 

    if(i<n+1)
    {
        while(i<n+1)
        {
            result[k][0]=sparse_arr1[i][0];
            result[k][1]=sparse_arr1[i][1];
            result[k][2]=sparse_arr1[i][2];
            k++; i++;   
        }
    }

    if(j<m+1)
    {
        while(j<m+1)
        {
            result[k][0]=sparse_arr2[j][0];
            result[k][1]=sparse_arr2[j][1];
            result[k][2]=sparse_arr2[j][2];
            k++; j++;
        }
    }
    result[0][2]=k-1;
    // Displaying the sparse matrix

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int sparse_1[4][4]={
        {0,0,1,0},
        {8,3,0,0},
        {0,7,4,0},
        {0,0,0,0}
    };
    int sp_1[6][3]={
        {4,4,5},
        {0,2,1},
        {1,0,8},
        {1,1,3},
        {2,1,7},
        {2,2,4},
    };
    int sparse_2[4][4]={
        {0,0,0,0},
        {8,1,0,0},
        {0,0,4,7},
        {0,4,6,0}
    };
    int sp_2[7][3]={
        {4,4,6},
        {1,0,8},
        {1,1,1},
        {2,2,4},
        {2,3,7},
        {3,1,4},
        {3,2,6}
    };
    sparse_add(sp_1,sp_2,5,6);
    return 0;
}