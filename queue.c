#include <stdio.h>
#define MAX 20
#include<stdlib.h>
int Queue_from_array[MAX];
int rear = - 1;
int front = - 1;
void insert_queue()
{
      int add_element;
      if (rear == MAX - 1)
            printf("Overflow\n\n");
      else
      {
            if (front == - 1)
                  /*If queue is initially empty */
            front = 0;
            printf("Enter element: \n");
            scanf("%d", &add_element);
            printf("%d is inserted in queue\n\n",add_element);
            rear = rear + 1;
            Queue_from_array[rear] = add_element;
      }
}
void delete_queue()
{
      if (front == - 1 || front > rear)
      {
            printf("Underflow\n\n");
            return ;
      }
      else
      {
            printf("Deleted element : %d\n\n", Queue_from_array[front]);
            front = front + 1;
      }
}
void display_queue()
{
      int i;
      if (front == - 1)
            printf("Empty queue!\n\n");
      else
      {
            printf("Queue is : ");
            for (i = front; i <= rear; i++)
                  printf("%d ", Queue_from_array[i]);
            printf("\n");
      }
}
int main()
{
      printf("LIST OF OPERATIONS\n\n");
      printf("\t 1. Insert element: \n");
      printf("\t 2. Delete element: \n");
      printf("\t 3. Display queue\\n");
      printf("\t 4. Exit\n");
      int op;
      while (1)
      {
            printf("\nChoose an operation number: ");
            scanf("%d", &op);
            switch(op)
            {
                  case 1:
                        insert_queue();
                        break;
                  case 2:
                        delete_queue();
                        break;
                  case 3:
                        display_queue();
                        break;
                  case 4:
                        exit(1);
                  default:
                        printf("This is an invalid operation\n");
            }
      }
      return 0;
}
