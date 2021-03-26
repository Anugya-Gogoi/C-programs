#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first;
int push();
int pop();
int print();

int pop()
{
    if(first==NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        struct node *ptr,*cpt;
        ptr=first;
        cpt=ptr->next;
        first=cpt;
        printf("\nData Popped : %d\n",ptr->data);
        free(ptr);
    }
    return 0;
}

int push()
{
    if(first==NULL)
    {
            struct node *ptr;
            ptr=(struct node *)malloc(sizeof(struct node));
            printf("Enter Data : \n");
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            first=ptr;
            printf("Data PUSHED : %d\n=",ptr->data);
    }
    else
    {
        struct node *ptr,*cpt;
        ptr=first;
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->next=ptr;
        ptr=cpt;
        first=ptr;
        printf("\nData PUSHED : %d\n",cpt->data);
    }
    return 0;
}

int print()
{
    struct node *ptr;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nEmpty stack\n");
    }
    else
    {
        printf("\nData In Stack\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
    return 0;
}

int main()
{
    int choice;
    do
    {
        printf("\n1.Pop\n2.Push\n3.Print\n4.Exit\n\n");
        printf("\nEnter operation number ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: pop();
                    break;
            case 2: push();
                    break;
            case 3: print();
                    break;
            case 4: exit(0);
                    break;
            default : printf("\nEnter a valid operation number\n");
        }
    }
    while(choice!=4);
return 0;
}
