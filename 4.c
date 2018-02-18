#include<stdio.h>
#include<stdlib.h>

void binary_search(int *, int);

int main()
{
    int ch, i, *arr, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("Enter array in sorted order only...\n");
    for(i = 0; i < size; i++)
    {
        printf("\n\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\n\n\n");
        printf("__________________________________\n");
        printf("Enter choice:\n1: Search\n2: Exit\n");
        printf("__________________________________\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: binary_search(arr, size);
                    break;
            case 2: break;
            default: printf("\n\nWrong choice");
        }
    }while(ch!=2);
    return 0;
}

void binary_search(int *arr, int size)
{
    printf("\n\n\n\n\n");
    if(size == 0)
    {
        printf("\n\n\nUnderflow");
    }
    else
    {
        int ele, i, beg = 0, end = size - 1, mid;
        int found = 0;
        printf("\n\nEnter element to be searched: ");
        scanf("%d", &ele);
        while(beg <= end && found == 0)
        {
            mid = (beg+end)/2;
            if(arr[mid] == ele)
            {
                found = 1;
            }
            else if(ele > arr[mid])
            {
                beg = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        if (found == 0)
            printf("Not found");
        else
            printf("Found at location: %d", mid+1);
    }
}
