#include <stdio.h>
int array[40],n;


void display()
{   int i;
	if(n==0)
	{
		printf("Heap is empty\n");
		return;
	}
	for(i=0;i<n;i++)
		printf("\n%d ",array[i]);
	printf("\n");
}

void insert(int num,int posn)
{
	int ele;
	while(posn>0)
	{
		ele=(posn-1)/2;
		if(num<=array[ele])
		{
			array[posn]=num;
			return;
		}
		array[posn]=array[ele];
		posn=ele;
	}
	array[0]=num;
}

void del(int num)
{
	int left,right,i,temp,ele;

	for(i=0;i<n;i++)
	{
		if(num==array[i])
		break;
	}
	if( num!=array[i] )
	{
		printf("\n %d not found in heap\n",num);
		return;
	}
	array[i]=array[n-1];
	n=n-1;
	ele=(i-1)/2;
	if(array[i] > array[ele])
	{
		insert( array[i],i);
		return;
	}
	left=2*i+1;
	right=2*i+2;
	while(right < n)
	{
		if( array[i]>=array[left] && array[i]>=array[right] )
			return;
		if( array[right]<=array[left] )
		{
			temp=array[i];
			array[i]=array[left];
			array[left]=temp;
			i=left;
		}
		else
		{
			temp=array[i];
			array[i]=array[right];
			array[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;
	}
	if( left==n-1 && array[i]<array[left] )
	{	temp=array[i];
		array[i]=array[left];
		array[left]=temp;
	}
}

void main()
{
	int choice,num;
	n=0;
	while(1)
	{
		printf("\n\nOperations:\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("\nEnter the number to be inserted : ");
			scanf("%d",&num);
			insert(num,n);
			n=n+1;
			break;
		 case 2:
			printf("\nEnter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			display();
			break;
		 case 4:
            exit(0);
		 default:
			printf("Wrong choice\n");
		}
	}
}
