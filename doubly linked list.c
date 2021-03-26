//c program for double linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *nxt;
};
struct node *head;
void insert_at_beg();
void insert_at_end();
void insert_at_mid();
void delete_at_beg();
void delete_at_end();
void delete_at_mid();
void display();
void main ()
{
int option_required = 0;
    while(option_required != 9)
    {
        printf("\nChoose any operation\n\n");
        printf("\n1.Insert at the begining\n2.Insert at the last\n3.Insert at middle\n4.Delete from beginning\n5.Delete from end\n6.Delete at middle in the node\n7.Display list\n8.Exit\n");
        printf("\nEnter your choice number\n");
        scanf("\n%d",&option_required);
        switch(option_required)
        {
            case 1:
            insert_at_beg();
            break;
            case 2:
            insert_at_end();
            break;
            case 3:
            insert_at_mid();
            break;
            case 4:
            delete_at_beg();
            break;
            case 5:
            delete_at_end();
            break;
            case 6:
            delete_at_mid();
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            break;
            default:
            printf("Invalid!");
        }
    }
}
void insert_at_beg()
{
   struct node *ptr;
   int ELEMENT;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nSTACK OVERFLOW");
   }
   else
   {
    printf("\nEnter number");
    scanf("%d",&ELEMENT);

   if(head==NULL)
   {
       ptr->nxt = NULL;
       ptr->prev=NULL;
       ptr->data=ELEMENT;
       head=ptr;
   }
   else
   {
       ptr->data=ELEMENT;
       ptr->prev=NULL;
       ptr->nxt = head;
       head->prev=ptr;
       head=ptr;
   }
   printf("\nNode inserted\n");
}

}
void insert_at_end()
{
   struct node *ptr,*temp;
   int ELEMENT;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
   }
   else
   {
       printf("\nEnter value");
       scanf("%d",&ELEMENT);
        ptr->data=ELEMENT;
       if(head == NULL)
       {
           ptr->nxt = NULL;
           ptr->prev = NULL;
           head = ptr;
       }
       else
       {
          temp = head;
          while(temp->nxt!=NULL)
          {
              temp = temp->nxt;
          }
          temp->nxt = ptr;
          ptr ->prev=temp;
          ptr->nxt = NULL;
          }

       }
     printf("\nnode inserted\n");
    }
void insert_at_mid()
{
   struct node *ptr,*temp;
   int ELEMENT,loc,i;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n STACK OVERFLOW");
   }
   else
   {
       temp=head;
       printf("Enter the location");
       scanf("%d",&loc);
       for(i=0;i<loc-1;i++)
       {
           temp = temp->nxt;
           if(temp == NULL)
           {
               printf("\n There are less than %d elements", loc);
               return;
           }
       }
       printf("Enter value");
       scanf("%d",&ELEMENT);
       ptr->data = ELEMENT;
       ptr->nxt = temp->nxt;
       ptr -> prev = temp;
       temp->nxt = ptr;
       temp->nxt->prev=ptr;
       printf("\nThe node is inserted\n");
   }
}
void delete_at_beg()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if(head->nxt == NULL)
    {
        head = NULL;
        free(head);
        printf("\nThe node is deleted\n");
    }
    else
    {
        ptr = head;
        head = head -> nxt;
        head -> prev = NULL;
        free(ptr);
        printf("\nThe node is deleted\n");
    }

}
void delete_at_end()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n STACK UNDERFLOW");
    }
    else if(head->nxt == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        if(ptr->nxt != NULL)
        {
            ptr = ptr->nxt;
        }
        ptr->prev->nxt = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void delete_at_mid()
{
    struct node *ptr, *temp;
    int value;
    printf("\n Enter the number after which the node is to be deleted : ");
    scanf("%d", &value);
    ptr = head;
    while(ptr->data != value)
    ptr = ptr->nxt;
    if(ptr->nxt == NULL)
    {
        printf("\nNot deleted\n");
    }
    else if(ptr -> nxt -> nxt == NULL)
    {
        ptr ->nxt = NULL;
    }
    else
    {
        temp = ptr->nxt;
        ptr->nxt = temp->nxt;
        temp->nxt->prev = ptr;
        free(temp);
        printf("\nnode deleted\n");
    }
}
void display()
{
    struct node *ptr;
    printf("\n The values are: \n");
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->nxt;
    }
}

