#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void display(int arr[], int size);
void merge_func(int arr[], int mid, int beg, int end);
void sort_func(int arr[], int left, int right);

void display(int arr[], int size)
{
	int i;
	for(i=0; i < size; i++)
	printf("%d ", arr[i]);
	printf("\n");
}

void merge_func(int arr[], int beg, int mid, int end)
{
	int x, y, z;
	int L = mid - beg + 1;
	int R = end - mid;
	int leftArray[L], rightArray[R];
	for (x = 0; x < L; x++)
	leftArray[x] = arr[beg + x];
	for (y = 0; y < R; y++)
	rightArray[y] = arr[mid + 1 + y];
	x = 0;
	y = 0;
	z = beg;
	while(x < L && y < R)
	{
		if(leftArray[x] <= rightArray[y])
		{
			arr[z] = leftArray[x];
			x++;
		}
		else
		{
			arr[z] = rightArray[y];
			y++;
		}
		z++;
	}
	while(x < L)
	{
		arr[z] = leftArray[x];
		x++;
		z++;
	}
	while(y < R)
	{
		arr[z] = rightArray[y];
		y++;
		z++;
	}
}

void sort_func(int arr[], int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = left + (right - left) / 2;
		sort_func(arr, left, mid);
		sort_func(arr, mid + 1, right);
		merge_func(arr, left, mid, right);		
	}
}

void main()
{
	
	int array[90];
	int i, size;
	printf("Enter the number of integers: ");
	scanf("%d", &size);
	printf("Enter the integers: ");
	for(i = 0; i < size; i++)
	{
	printf("\nNumber %d", i+1);
	scanf("%d", &array[i]);
	}
	printf("The unsorted array: ");
	display(array, size);
	sort_func(array, 0, size-1);
	printf("The sorted Array: ");
	display(array, size);	

	clock_t start, end;
	double cpu_time_used;
	start = clock();
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime is: %lf \n\n", cpu_time_used);
	
}    
