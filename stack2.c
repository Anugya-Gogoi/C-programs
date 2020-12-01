//Also implement the C program to evaluate the value of the expression from the postfix notation using stack.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[40];
int first=-1;
int flag=0;
int pop()
{
        int value= stack[first];
        first=first-1;
        return value;

}
void push(int element)
{
  if(flag==1){
    int num;
    num=pop();
    stack[++first]=element + 10*num;
  }
  else if(flag==0){
    stack[++first]=element;
    flag=1;
  }
}

void evaluate(char st[])
{
    int i=0, a, b, value;
    char ch;
    while( (ch=st[i++]) != ')')
    {
        if(ch==' ')
        flag=0;
         else if(isdigit(ch))
         push(ch-'0');
        else

        {
            flag=0;
            a=pop();
            b=pop();
            switch(ch)
            {
                case '*':
                     value=b*a;
                     break;
                case '/':
                     value=b/a;
                     break;
                case '+':
                     value=b+a;
                     break;
                case '-':
                     value=b-a;
                     break;
            }
            push(value);
        }

    }
            printf("\n\n Result = %d \n", pop());

}

int main()
{
    char postfix[]= "6 5 4 / + 3 4 * 3 * - 12 - )";
    printf("\n\n The given expression is 6 5 4 / + 3 4 * 3 * - 12 -");
    evaluate(postfix);
    return 0;
}
