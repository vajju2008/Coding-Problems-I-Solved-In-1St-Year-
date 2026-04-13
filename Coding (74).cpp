#include<stdio.h>
int bomb();
int p;
int sum = 5;
int main() {
p = bomb();
printf("%d %d",sum,p);
return 0;
}
int bomb(){
	sum=sum+1;
	return(sum);
}
