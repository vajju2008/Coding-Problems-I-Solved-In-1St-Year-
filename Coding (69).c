//decimalto binary conversion
#include<stdio.h>
int main(){
	int n,i,rem,bin=0;
	printf("enter decimal number \n");
	scanf("%d",&n);
	i=1;
	while(n!=0)
	{
		rem=(n%2);
		n=(n/2);
		bin=bin+rem*1;
		i=i*10;	
	}
	printf("binary number is %d",bin);
	return 0;
}
