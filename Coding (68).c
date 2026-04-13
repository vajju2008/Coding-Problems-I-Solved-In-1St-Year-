#include<stdio.h>
 int main(){
 	float amount;
 	float tax;
 	double tot_amount;
 	    int amo=amount;
	printf("enter the amount :");
	scanf("%f",&amount);
      tax = 0.18;
	printf("the tax on the products : %f",tax);
 	tot_amount = (amount+tax);
	printf("total amount=%lf",tot_amount);
}