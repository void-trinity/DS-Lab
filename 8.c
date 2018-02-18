#include<stdio.h>
#include<stdlib.h>
void PUSH(int*, int*, int);
void POP(int*, int*);
void view(int*, int);
int main()
{
    int *stack, TOP = -1, size, ch;
    printf("Siddharth Chandra, 16115078");
    printf("\nEnter size of stack: ");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
    do
    {
        printf("\n\n\n");
        printf("Enter choice:\n1: Push\n2: Pop\n3: View\n4: Exit");
        printf("\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: PUSH(stack, &TOP, size);
                break;
            case 2: POP(stack, &TOP);
                break;
            case 3: view(stack, TOP);
                break;
            case 4: break;
            default: printf("\nWrong choice....");
        }
    }while(ch!=4);
    return 0;
}

void PUSH(int *stack, int *TOP, int size)
{
    if(*TOP == size-1)
    {
        printf("\nOverflow");
    }
    else
    {
        int ele;
        printf("Enter element to be inserted: ");
        scanf("%d", &ele);
        (*TOP)++;
        stack[*TOP] = ele;
    }
}

void POP(int *stack, int *TOP)
{
    if(*TOP == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        int ele;
        ele = stack[*TOP];
        (*TOP)--;
        printf("\nElement %d was deleted", ele);
    }
}

void view(int *stack, int TOP)
{
    int i;
    printf("\n\n\nThe stack is: ");
    for(i = 0; i <= TOP; i++)
    {
        printf("%d\t", stack[i]);
    }
}
