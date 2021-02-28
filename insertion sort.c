#include<stdio.h>
void main()
{
    int arr[10],n,i,temp,j;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the values");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }

    printf("The insertion sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

}
