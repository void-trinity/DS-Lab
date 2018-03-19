// Linked List implementation of Queue

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL,*rear = NULL;

void enQueue(int value)
{
   struct Node *newNode;
   newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(rear==NULL)
      newNode->next=NULL;
   else
      newNode->next=rear;
   front=rear=newNode;
   printf("Insertion Successful !!\n");
}

void deQueue()
{
   if(front==NULL)
      printf("Queue is Empty !!\n");
   else
   {
      struct Node *temp=front;
      printf("Deleted element: %d\n",temp->data);
      front=temp->next;
      free(temp);
   }
}
void display()
{
   if(front==NULL && rear==NULL)
      printf("Queue is Empty !!\n");
   else
   {
      struct Node *temp=rear;
      printf("Queue : ");
      while(temp->next!=NULL)
      {
        printf("%d --> ",temp->data);
        temp = temp -> next;
      }
      printf("%d --> NULL\n",temp->data);
   }
}

int main()
{
    int ch,val;
    printf("Neeraj Jain \nQueue Implementation Using Linked List\n");
    while(1)
    {
        printf("\nAvailable Choices \n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter Value for Insertion : ");
                     scanf("%d", &val);
                     enQueue(val);
                     break;
            case 2 : deQueue();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
            default: printf("\nInvalid Choice !! Please try again...\n");
        }
    }
    return 0;
}
