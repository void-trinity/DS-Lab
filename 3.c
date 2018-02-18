#include<stdio.h>
#include<stdlib.h>

void search(int *, int);

int main()
{
    int ch, i;
    int *arr, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
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
            case 1: search(arr, size);
                    break;
            case 2: break;
            default: printf("\n\nWrong choice");
        }
    }while(ch!=2);
    return 0;
}


void search(int *arr, int size)
{
    printf("\n\n\n\n\n");
    if(size == 0)
    {
        printf("\n\n\nUnderflow");
    }
    else
    {
        int ele, i, found;
        found = 0;
        printf("\n\nEnter element to be searched: ");
        scanf("%d", &ele);
        for(i = 0; i < size; i++)
        {
            if(arr[i] == ele)
            {
                printf("\n\nFound at location %d", i+1);
                found = 1;
            }
        }
        if (found == 0)
        {
            printf("\n\nElement not found");
        }
    }
}
