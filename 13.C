#include <stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice = 1;
    while (choice != 6)
    {
        printf("\n\n\n");
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Size \n");
        printf("5.Empty \n");
        printf("6.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                size();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                break;
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}
void insert()
{
    int item;
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == - 1)
            front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &item);
        rear++;
        queue_array[rear] = item;
    }
}

void delete()
{
    int ele;
    if (front == - 1)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        ele = queue_array[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;

        }
        else
        {
            front++;
        }
        printf("Element deleted from queue is : %d\n", ele);
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

void size()
{
    int size = front == -1 ? 0 : rear-front+1;
    printf("\nSize: %d", size);
}

void isEmpty()
{
    if (front == -1)
        printf("\nEmpty");
    else
        printf("\nNot Empty");
}
