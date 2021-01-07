//Implement C program for  conversion of the postfix notation from infix notation of the numerical statement 6+5/4-3*4*3-12 using stack.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

char infix_string[30], postfix_str[30];
int top;
int stack[30];

int pop();
int order(char exp);
int emptystr();
void infix_to_postfix();
int check_space(char exp);
void push(long int exp);

int main()
{
int count, length;
char temp;
top = -1;
printf("\nENTER THE INFIX EXPRESSION : ");
scanf("%s", infix_string);
infix_to_postfix();
printf("\nTHE POSTFIX EXPRESSION : %s\n", postfix_str);
return 0;
}

void infix_to_postfix()
{
unsigned int count, temp = 0;
char next;
char exp;
for(count = 0; count < strlen(infix_string); count++)
{
exp = infix_string[count];
if(!check_space(exp))
{
switch(exp)
{
case '(': push(exp);
break;
case ')':
while((next = pop()) != '(')
{
postfix_str[temp++] = next;
}
break;
case '+':
case '-':
case '*':
case '/':
case '%':
case '^':
while(!emptystr() && order(stack[top]) >= order(exp))
postfix_str[temp++] = pop();
push(exp);
break;
default:
postfix_str[temp++] = exp;
}
}
}

while(!emptystr())
{
postfix_str[temp++] = pop();
}
postfix_str[temp] = '\0';
}

int order(char exp)
{
switch(exp)
{
case '(': return 0;
case '+':
case '-':
return 1;
case '*':
case '/':
case '%':
return 2;
case '^':
return 3;
default:
return 0;
}
}

int check_space(char exp)
{
if(exp == '\t' || exp == ' ' )
{
return 1;
}
else
{
return 0;
}
}

void push(long int exp)
{
if(top > 30)
{
printf("\n Stack Overflow! \n");
exit(1);
}
top = top + 1;
stack[top] = exp;
}

int emptystr()
{
if(top == -1)
{
return 1;
}
else
{
return 0;
}
}

int pop()
{
if(emptystr())
{
printf("Empty Stack!\n");
exit(1);
}
return(stack[top--]);
}
