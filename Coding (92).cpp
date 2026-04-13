 #include<stdio.h>
 int main()
{
	int a=20;
	int b=10;
	int c;
	c=b;
	b=a;
	a=c;
	printf("value of a %d\n",a);
	printf("value of b %d\n",b);
	return 0;
}