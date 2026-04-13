//binary to decimal
#include <stdio.h>
int main(){
	int n,base,dec=0,rem;
	printf("enter binary number\n");
	scanf("%d",&n);
	base=1;
	while(n!=0)
	{
		rem=(n%10);
		n=(n/10);
		dec=dec+rem*base;
	    base=base*2;
	}
	printf("decimal number is %d",dec);
	return 0;
}