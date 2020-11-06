#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 5

int top=-1,stack[MAX];
void push();
void pop();
void display();

void main()
{
	int op;

	while(1)
	{
		printf("LIST OF OPERATIONS\n\n");
		printf("\t1.Push\n \t2.Pop\n \t3.Display\n \t4.Exit \n\n");
		printf("Choose your operation number:");
		scanf("%d",&op);

		switch(op)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);

			default: printf("\nWrong opoice!!");
		}
	}
}

void push()
{
	int val;

	if(top==MAX-1)
	{
		printf("\nStack is full!!");
	}
	else
	{
		printf("\nEnter element to push:");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nDeleted element is %d",stack[top]);
		top=top-1;
	}
}

void display()
{
	int i;

	if(top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nStack is...\n");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}
