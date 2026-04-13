#include<stdio.h>
int main ()
{
int peg_A=20,peg_B=10,peg_C;
peg_C=peg_A;
peg_A=peg_B;
peg_B=peg_C;
printf("%d %d",peg_A,peg_B);
return 0;
}