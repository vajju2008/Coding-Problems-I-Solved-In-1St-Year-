#include<stdio.h>
static int glnt = 1;
static void staticDemo(){
	static int i;
	printf("%d",i);
	i=i+1;
	printf("%d\n",glnt);
	glnt =glnt+1;
}
int main(){
	staticDemo();
	staticDemo();
}
