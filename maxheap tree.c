//maxheap tree

#include <stdio.h>

int size = 0;
int swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
  return 0;
}

int maxheap(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Only one element in the tree\n");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      maxheap(array, size, largest);
    }
  }
  return 0;
}

int insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      maxheap(array, size, i);
    }
  }
  return 0;
}

int delRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    maxheap(array, size, i);
  }
  return 0;
}

int printArr(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d\t", array[i]);
  return 0;
}

void main()
{
	int ele,num;
    int array[20];
	while(1)
	{
		printf("\n\nOPERATIONS:\n");
		printf("1.Insert element\n2.Delete element\n3.Display tree\n4.Exit program\n");
		printf("Enter operation number: ");
		scanf("%d",&ele);

		switch(ele)
		{
		 case 1:
		     {
            int p;
			printf("\nEnter the number to be inserted ");
			scanf("%d",&p);
			insert(array,p);
		     }
            break;

		 case 2:
            {
            int q;
			printf("\nEnter the number to be deleted ");
            scanf("%d",&q);
            delRoot(array,q);
            }
			break;

		 case 3:
			printArr(array,size);
			break;

		 case 4: exit(0);

		 default:
			printf("Invalid operation number\n");
		}

	}
}
