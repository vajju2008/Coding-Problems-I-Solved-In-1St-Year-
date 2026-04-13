#include <stdio.h>
int main()

{
	int a;
	scanf("%d",&a);
	if(a%2==0 && a%7==0)
	printf("alice");
	else if (a%2!=0 && a%9==0)
	printf("bob");
	else printf("charlie");
}