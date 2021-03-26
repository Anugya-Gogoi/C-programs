#include <stdio.h>
#define size 7
#define sizeM 7

void disp(int arr[])
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insrt(int arr[size], int pos, int ele)
{
	int oldVal;
	if(pos == 0 || pos > size)
	{
		printf("\nSize of the array is %d\n", size);
		printf("\n%d not inserted\n", ele);
		return;
	}
	oldVal = arr[pos-1];
	arr[pos-1] = ele;
	if(oldVal != 0)
		printf("\nElement %d replaced with %d in the array at position %d.\n", oldVal, ele, pos);
	else
		printf("\n%d added to the Array at position %d.\n", ele, pos);
	printf("The updated array is:\n");
	disp(arr);
	return;
}

void del(int arr[], int pos)
{
	if(pos == 0 || pos > size)
	{
		printf("\nSize of the array is %d.", size);
		printf("\nNothing deleted from the array.\n");
		return;
	}
	int ele = arr[pos-1];
	arr[pos-1] = 0;
	printf("\n%d deleted from the position %d of the Array.\n", ele, pos);
	printf("The updated array is:\n");
	disp(arr);
	printf("\n");
	return;
}

void mergeArray(int arr1[], int arr2[])
{
	int i;
	int mergedArray[size + sizeM];
	for(i = 0; i < size; i++)
	{
		mergedArray[i] = arr1[i];
		mergedArray[i + size] = arr2[i];
	}
	while(arr2[i] != '\0')
		mergedArray[i + size] = arr2[i];
	printf("\nArray after merging: ");
	for(i = 0; i < size + sizeM; i++)
		printf("%d ", mergedArray[i]);
	printf("\n");
}

int main()
{
	int arr[size], arrM[sizeM + 1] = {'\0'};
	int opt = 0, pos, ele, i;
	for(i = 0; i < size; i++)
		arr[i]= 0;
	printf("Array Size: %d\n", size);
	while (opt != 5)
	{
		printf("\nOptions:\n\n1. Insert element.\n2. Delete element.\n3. Merge another 1-D array.\n4. Display the Array.\n5. Exit the program.");
		printf("\nEnter your choice: ");
		scanf("%d", &opt);
		if(opt == 1)
		{
			printf("Enter the position of the new element: ");
			scanf("%d", &pos);
			printf("Enter the new element (integer): ");
			scanf("%d", &ele);
			insrt(arr, pos, ele);
		}
		else if (opt == 2)
		{
			printf("Enter the position of the element to be deleted: ");
			scanf("%d", &pos);
			del(arr, pos);
		}
		else if(opt == 3)
		{
			printf("Enter the new array of size %d to be merged to the primary array:\n", sizeM);
			for(i = 0; i < sizeM; i++)
			{
				printf("\tEnter Element %d: ", i+1);
				scanf("%d", &arrM[i]);
			}
			mergeArray(arr, arrM);
		}
		else if(opt == 4)
		{
			printf("\nThe Array is: ");
			disp(arr);
		}
		else if(opt ==5)
			printf("\nExiting the program.");
		else
			printf("\nInvalid Option. Please try again.\n");
	}
	return 0;
}
