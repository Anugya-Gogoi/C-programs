#include <stdio.h>
void main()
{
  int arr[50], n, i, d, pos, t;
  printf("\n\nEnter the number of elements ");
  scanf("%d", &n);
  printf("Enter %d integers\n", n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for (i = 0; i < (n - 1); i++)
  {
    pos = i;
    for (d = i + 1; d < n; d++)
    {
      if (arr[pos] > arr[d])
        pos = d;
    }
    if (pos != i)
    {
      t = arr[i];
      arr[i] = arr[pos];
      arr[pos] = t;
    }
  }

  printf("\nSelection sorted list is:\n");
  for (i = 0; i < n; i++)
    printf("%d\t", arr[i]);
}
