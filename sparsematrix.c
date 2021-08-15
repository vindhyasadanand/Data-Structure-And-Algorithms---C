#include <stdio.h>

int main()
{
    int r,c,i,j,total=0;
    printf("Enter no of rows");
    scanf("%d",&r);
    printf("Enter no of columns");
    scanf("%d",&c);
    int mat[r][c];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat[i][j]==0)
            {
                total++;
            }
        }
    }
    if(total>(r*c)/2)
    {
        printf("Sparse matrix");
    }
    return 0;
}
