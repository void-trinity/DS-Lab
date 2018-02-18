#include<stdio.h>
#include<stdlib.h>
void traverse(int*, int, int);
int insert(int*, int, int);
int delet(int*, int, int);

int main()
{
    int ch, i;
    int *arr, size, noe;
    printf("Enter size of array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    noe = size;
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\n\n\n");
        printf("__________________________________\n");
        printf("Enter choice:\n1: Traversal\n2: Insert\n3: Delete\n4: Exit\n");
        printf("__________________________________\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: traverse(arr, size, noe);
                    break;
            case 2: noe = insert(arr, size, noe);
                    break;
            case 3: noe = delet(arr, size, noe);
                    break;
            case 4: break;
            default: printf("Wrong choice");
        }
    }while(ch!=4);
    return 0;
}




void traverse(int *arr, int size, int noe)
{
    int i;
    printf("\n\n\n");
    for(i = 0; i < noe; i++)
    {
        printf("%d\t",arr[i]);
    }
}
int insert(int *arr, int size, int noe)
{
    int i, pos, ele;
    printf("\n\n\n");
    if (noe == size)
    {
        printf("Overflow");
    }
    else
    {
        noe++;
l:      printf("\n\nEnter position where element is to be inserted: ");
        scanf("%d", &pos);
        if(pos > size || pos <= 0)
        {
            printf("Invalid position, try again!\n");
            goto l;
        }
        printf("\n\nEnter element to be inserted: ");
        scanf("%d", &ele);
        for(i = noe; i >= pos; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[pos-1] = ele;
        printf("\nElement has been inserted");
    }
    return noe;
}
int delet(int *arr, int size, int noe)
{
    printf("\n\n\n");
    if(noe == 0)
    {
        printf("Underflow");
    }
    else
    {
        int pos, ele, i;
m:      printf("\n\nEnter position where element is to be deleted: ");
        scanf("%d", &pos);
        if(pos > noe || pos <= 0)
        {
            printf("Invalid position, try again!\n");
            goto m;
        }
        ele = arr[pos-1];
        for(i = pos-1; i < noe-1; i++)
        {
            arr[i] = arr[i+1];
        }
        noe--;
        printf("Element %d was deleted", ele);
    }
    return noe;
}
