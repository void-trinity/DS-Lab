// Linked List Implementation of Stack

#include<stdio.h>

struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

void push(int value)
{
   struct Node *newNode;
   newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top==NULL)
      newNode->next=NULL;
   else
      newNode->next=top;
   top=newNode;
   printf("Insertion Successful !!\n");
}

void pop()
{
   if(top == NULL)
      printf("Stack is Empty !!\n");
   else{
      struct Node *temp = top;
      printf("Deleted element: %d\n", temp->data);
      top = temp->next;
      free(temp);
   }
}
void display()
{
   if(top==NULL)
      printf("Stack is Empty !!\n");
   else
   {
      struct Node *temp=top;
      printf("Stack : ");
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
   printf("Neeraj Jain \nStack Implementation Using Linked List\n");
   while(1)
   {
        printf("\nAvailable Choices \n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter Value for Insertion : ");
                     scanf("%d", &val);
                     push(val);
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
            default: printf("\nInvalid Choice !! Please try again...\n");
      }
   }
   return 0;
}

