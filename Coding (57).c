#include<stdio.h>
int main()
{
	float tran_amt;
	int amt;
	double tax;
	printf("\n Enter transaction amount:");
	scanf("%f",&tran_amt);
	amt=tran_amt;
	tax=0.18*tran_amt;
	printf("\n Transaction Amount:%0.2f",tran_amt);
	printf("\n Integer Amount:%d",amt);
	printf("\n Tax Amount:%lf",tax);
	return 0;
}