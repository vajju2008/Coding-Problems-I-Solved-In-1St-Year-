
#include<stdio.h>
int main()
{
	unsigned char a=0xFA;
	a=(a>>4)|(a<<4);
	printf("a=%02x\n",a);
	return 0;
}