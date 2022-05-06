//DFA to accept even number of 0s and odd number of 1s 

#include<stdio.h>
int EE=0, OE=1, OO=2, EO=3;
int temp = 0;
char input;
int main(void) {
   printf("Enter a string of 0s and 1s: ");
   while (1) {
      scanf("%c", &input);
      if (input == '\n')
         break;
      if ( (input != '0') && (input != '1') ) {
         break;
      }
      if (temp==0) {
         temp = (input == '0') ? OE : EO;
      }
      else if(temp==1) {
         temp = (input == '0') ? EE : OO;
      }
      else if (temp==2) {
         temp = (input == '0') ? EO : OE;
      } else {
         temp = (input == '0') ? OO : EE;
      }
   };
   if (input == '\n') {
      if (temp == EO)
         printf("\nInput accepted");
      else
         printf("\nInput rejected");
   }
   return 0;
}
