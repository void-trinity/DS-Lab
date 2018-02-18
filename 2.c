#include<stdio.h>
#include<stdlib.h>

void smallest(int*, int);
void largest(int*, int);
int main()
{
    int ch, i;
    int *arr, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\n\n\n");
        printf("__________________________________\n");
        printf("Enter choice:\n1: Smallest\n2: Largest\n3: Exit\n");
        printf("__________________________________\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: smallest(arr, size);
                    break;
            case 2: largest(arr, size);
                    break;
            case 3: break;
            default: printf("Wrong choice");
        }
    }while(ch!=3);
    return 0;
}
void smallest(int *arr, int size)
{
    printf("\n\n\n");
    if(size == 0)
    {
        printf("Underflow");
    }
    else
    {
        int small = arr[0], i;
        for(i = 1; i < size; i++)
        {
            if (arr[i] < small)
                small = arr[i];
        }
        printf("Smallest element is: %d", small);
    }
}

void largest(int *arr, int size)
{
    printf("\n\n\n");
    if(size == 0)
    {
        printf("Underflow");
    }
    else
    {
        int large = arr[0], i;
        for(i = 1; i < size; i++)
        {
            if (arr[i] > large)
                large = arr[i];
        }
        printf("Largest element is: %d", large);
    }
}
