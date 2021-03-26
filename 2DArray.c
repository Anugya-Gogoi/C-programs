#include<stdio.h>

int arr[40][40]={0};

void delete(int a, int b){
if(a==0 && b==0){
      printf("Array is empty!\n");
      return;
    }
   else
   arr[a -1][b-1]=0;

}

void display(int a, int b){
 int i, j;
 for(i=0;i<a;i++){
    for(j=0;j<b;j++){
        printf("%d ",arr[i][j]);
     }
    printf("\n");
  }
}

void insert(int r, int c){
int i=0;
int j=0;
   for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        printf("\nEnter element for row %d column %d  ",i+1, j+1);
        scanf("%d",&arr[i][j]);
     }
  }
 }


int main(){


int p, q, i, j, a, b;
 printf("Enter the rows and columns of array:\n");
  scanf("%d %d", &p, &q);
  int arr[p][q];
  a=p, b=q;
  int opt;
  while(opt!=4){
    printf("\n\nChoose operation:\n\n1. Insertion \n2. Deletion \n3. Display \n4. Exit\n");
    scanf("%d",&opt);
    switch(opt){
       case 1: insert(p, q);
          break;
       case 2: delete(a, b);
           break;
       case 3: display(a, b);
           break;
       case 4: break;
       default: printf("Invalid option\n");
     }
     if(opt==4)
     break;
  }


  return 0;
}
