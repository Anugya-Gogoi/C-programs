/*Given an array of integers, a, return the maximum difference of any pair of numbers such that the larger integer in the pair occurs at a higher index
(in the array) than the smaller integer. Return -1 if you cannot find a pair that satisfies this condition.*/

#include<stdio.h>
int max(int x, int y)
{
    int m;
    if(x>y)
    {
        m=x;
    }
    else
    {
        m-y;
    }
    return m;
}

int maximumD(int arr[], int arr_size)
{
  int maxm = -1;
  int i, j, k;
  for (i = 0; i < arr_size-1; i++)
  {
    for (j = i+1; j < arr_size; j++)
    {
      if (arr[j] - arr[i] > maxm)
      {
          maxm = arr[j] - arr[i];
         k=max(k,maxm);
      }
    }
  }
  return maxm;
}

void main()
{
    int x, i;
    printf("Enter the array size: ");
    scanf("%d",&x);
    int arr[x];
    for(i=0;i<x;i++)
    {
        printf("Enter element number %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Entered elements are:\n");
       for(i=0;i<x;i++)
    {

        printf("%d\t",arr[i]);
    }

    int p;
    p=maximumD(arr,x);
    printf("\nMaximum difference=%d",p);
}
