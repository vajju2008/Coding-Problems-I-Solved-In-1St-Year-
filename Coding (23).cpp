#include<stdio.h>
int main()
{
	int n,sum=0,r,temp;
	printf("enter n value:");
	scanf("%d",&n);
	while(n>0)
	{
		r=n%10;
		sum=(sum+(r*r*r));
		n=n/10;
	}
	if(temp==sum)
	{
	
	printf("arm strong number");
}
	else
	{
	
	printf("not");
 }
	return 0;
	
}