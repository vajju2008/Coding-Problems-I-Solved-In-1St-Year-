#include<stdio.h>
int main()
{
	FILE *fp;
	int avg;
	fp=fopen("res.txt","w");
	fprintf(fp,"10,12,13,22,34,44,45,5,55,7");
	avg=(10+12+13+22+34+44+45+5+55+7)/10;
	fprintf(fp,"%d",avg);
	fclose(fp);
}
