#include <stdio.h>
#include <string.h>
// Binary search for names
void search_name(char[][30], int);
int main()
{
    int size, i, ch;
    char name[30][30];
    printf("Enter the number of names you want to enter(max 30): ");
    scanf("%d", &size);
    printf("Enter names in SORTED order\n");
    for(i = 0; i < size; i++)
    {
        printf("Enter name %d: ", i+1);
        scanf("%s", name[i]);
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
            case 1: search_name(name, size);
                    break;
            case 2: break;
            default: printf("\n\nWrong choice");
        }
    }while(ch!=2);
    return 0;
}

void search_name(char name[30][30], int size)
{
    if(size == 0)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        char search[30];
        int beg = 0, end = size-1, mid, loc = -1;
        printf("Enter the name to be searched: ");
        scanf("%s", search);
        while(beg <= end && loc == -1)
        {
            mid = (beg+end)/2;
            if(strcmp(name[mid], search) == 0)
            {
                loc = mid;
            }
            else if(strcmp(name[mid], search) < 0)
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if(loc != -1)
            printf("\nElement found at %d", loc+1);
        else
            printf("\nElement not found");
    }
}
