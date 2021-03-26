#include <stdio.h>
#include <stdlib.h>
#define MAX 40
void create();
void insert_by_priorQ(int);
void delete_by_priorQ(int);
void check(int);
void display_the_queue();
int priorQueue[MAX];
int front, rear;

int main()
{
    int n, val;
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    printf("\n4.Exit program");
    create();
 
    while (1)
    {
        printf("\n\nEnter the operation number ");    
        scanf("%d", &val);
 
        switch (val)
        {
        case 1: 
            printf("\nEnter value for insertion ");
            scanf("%d",&n);
            insert_by_priorQ(n);
            break;
        case 2:
            printf("\nEnter value for deletion ");
            scanf("%d",&n);
            delete_by_priorQ(n);
            break;
        case 3: 
            display_the_queue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nEnter operation choice only from the given list");
        }
    }
return 0;
}

void create()
{
    front = rear = -1;
}
void insert_by_priorQ(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nOverflow");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        priorQueue[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}

void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= priorQueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                priorQueue[j] = priorQueue[j - 1];
            }
            priorQueue[i] = data;
            return;
        }
    }
    priorQueue[i] = data;
}

void delete_by_priorQ(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == priorQueue[i])
        {
            for (; i < rear; i++)
            {
                priorQueue[i] = priorQueue[i + 1];
            }
 
        priorQueue[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not here", data);
}
void display_the_queue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nEmpty queue!");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", priorQueue[front]);
    }
 
    front = 0;
}
