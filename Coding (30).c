#include<stdio.h>
int main()
{
	int sum=0,n,digit,t;
	scanf("%d",&n);
	while(n!=0)
	{
		digit=n%10;
		sum=sum+digit*digit*digit;
		n=n/10;
	}printf("%d",sum);
	if(sum==t)
	{
		printf("\n given number is armstrong number");
	}
	else
	{
		printf("not");
	}
	return 0;
	
}