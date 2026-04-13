#include<stdio.h>
int main()
{
	int len,bre;
	float area;
	printf("\n Enter length of a rectangle:");
	scanf("%d",&len);
	printf("\n Enter Breadth of a rectangle:");
	scanf("%d",&bre);
	area=len*bre;
	printf("\n Length of a rectangle:%i",len);
	printf("\n Breadth of a rectangle:%i",bre);
	printf("\n Area of a rectangle:%f",area);
	
	
	return 0;
}