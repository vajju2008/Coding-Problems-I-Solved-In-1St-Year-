#include<stdio.h>
int sum(int n);
int main()
{
	int number,result;
	printf("enter a positive integer");
	scanf("%d",&number);v
	result=sum(number);
	printf("sum=%d",result);
	return 0;
}
int sum(int n)
{
	if(n!=0)
	  //sum () function call
	  return n- sum (n+1);
	else
	  return n;
}

