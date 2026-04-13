int main()
{
	int x=6;
	int N=4;
	int *ptr1,*ptr2;
	ptr1=&N;
	ptr2=&x;
	x=ptr1-ptr2;
	printf("Subtraction of ptr1 & ptr2 is:%d\n",x);
	
	return 0;
}