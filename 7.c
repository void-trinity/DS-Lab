#include<stdio.h>

int main()
{
    int a[100][100];
    int r,c,n,flag=0,zero=0,nonzero=0;

    printf(" Enter the no of rows and columns (both equal)\n");
    scanf("%d",&n);

    printf("Enter the elements\n");
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            scanf("%d",&a[r][c]);

            if(a[r][c]==0)
                zero++;
            else
                nonzero++;
        }
    }

    if(zero> nonzero)
        printf("The matrix is sparse\n");
    else
        printf("The matrix is not sparse\n");


    for(r=0; r<n; r++)
    {
         for(c=0; c<n; c++)
        {
            if(r>c)
            {
                if(a[r][c]!=0)
                {
                    flag=1;
                    break;
                }
            }
        }
    }

    if(flag==0)
        printf("Matrix is upper triangular\n");
    else
        printf("Matrix is not upper triangular\n");

    flag=0;


    for(r=0; r<n; r++)
    {
         for(c=0; c<n; c++)
        {
            if(r<c)
            {
                if(a[r][c]!=0)
                {
                    flag=1;
                    break;
                }
            }
        }
    }

    if(flag==0)
        printf("Matrix is lower triangular\n");
    else
        printf("Matrix is not lower triangular\n");

    flag=0;


    for(r=0; r<n; r++)
    {
         for(c=0; c<n; c++)
        {
            if(r!=c || r!=(c+1) || c!=(r+1))
            {
                if(a[r][c]!=0)
                {
                    flag=1;
                    break;
                }
            }
        }
    }

    if(flag==0)
        printf("Matrix is tri-diagonal\n");
    else
        printf("Matrix is not tri-diagonal\n");

}
