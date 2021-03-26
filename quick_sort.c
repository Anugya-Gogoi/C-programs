
#include<stdio.h>
void main(){
   int i, no, arr[50];
   printf("\n\nEnter the number of elements ");
   scanf("%d",&no);

   printf("Enter %d elements ", no);
   for(i=0;i<no;i++)
   scanf("%d",&arr[i]);

   quicksort(arr,0,no-1);
   printf("Sorted elements are: ");
   for(i=0;i<no;i++)
   printf(" %d",arr[i]);
}

void quicksort(int arr[50],int first,int last_ele){
   int i, j, a, temp;

   if(first<last_ele){
      a=first;
      i=first;
      j=last_ele;

      while(i<j){
         while(arr[i]<=arr[a]&&i<last_ele)
            i++;
         while(arr[j]>arr[a])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[a];
      arr[a]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last_ele);

   }
}
