#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char ch)
{
	if(top==MAX-1)
	{
		printf("Stack overflow!\n");
		return;
	}
	stack[++top]=ch;
}
char pop()
{
	if(top==-1)
	return '\0';
	return stack[top--];
}
int isMatchingPair(char opening,char closing){
	return(opening =='('&& closing ==')')||
	      (opening =='{'&& closing =='}')||
	      (opening =='['&& closing ==']');
}
int parentBalanced(char*exp)
{
	int i;top=-1;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		push(exp[i]);
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if(top==-1||!isMatchingPair(pop(),exp[i]))
			return 0;
		}
	}
	return (top==-1);
}
int main()
{
	char exp[MAX];
	printf("Enter an expression:");
	scanf("%s",exp);
	if(parentBalanced(exp))
	    printf("Balanced\n");
	else
	   printf("Not Balanced\n");
	   return 0;
}