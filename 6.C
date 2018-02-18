#include <stdio.h>
#include <stdlib.h>
// Sparse Matrix

void check_sparse(int*, int, int);
void transpose(int*, int, int);
void tuple(int*, int, int, int);

int main()
{
    int *mat, rows, cols, i, j;
    printf("Enter number of rows(max 50): ");
    scanf("%d", &rows);
    printf("Enter number of columns(max 50): ");
    scanf("%d", &cols);
    mat = (int*)malloc(rows*cols*sizeof(int));
    printf("Enter %d elements of the matrix: ", rows*cols);
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", mat+i*cols+j);
        }
    }

    printf("The entered matrix is:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", *(mat+i*cols+j));
        }
        printf("\n");
    }
    check_sparse(mat, rows, cols);
    return 0;
}

void check_sparse(int *mat, int rows, int cols)
{
    int i, j, count = 0;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(*((mat+i*cols) + j) == 0)
                count++;
        }
    }
    if (count > (rows*cols)/2)
    {
        printf("\n\nSparse Matrix");
        transpose(mat, rows, cols);
        tuple(mat, rows, cols, count);
    }
    else
        printf("Not a sparse, exiting....!");
}

void transpose(int *mat, int rows, int cols)
{
    int i, j;
    printf("\n\nTranspose of the matrix is:\n");
    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d\t", *((mat+j*cols) + i));
        }
        printf("\n");
    }
}

void tuple(int *mat, int rows, int cols, int count)
{
    int l = 1, p = rows * cols - count, i, j;
    printf("\n\n\n");
    printf("Three tuple notation of the matrix is:\n\n\n");
    printf("[0]\t%d\t%d\t%d\n", rows, cols, p);
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(*((mat+i*cols) + j) != 0)
            {
                printf("[%d]\t%d\t%d\t%d\n", l++, i, j, *((mat+i*cols)+j));
            }
        }
    }
}
