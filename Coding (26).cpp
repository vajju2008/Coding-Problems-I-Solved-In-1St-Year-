#include<stdio.h>
int main()

{
int i , j , n ,a[10],temp;
printf("enter the size of the array: ");
scanf("%d",&n);
printf("enter the elements in the array :");
for(i=0;i<n;i++)
{
scanf("%d\n",&a[i]);

}
printf("elements before sorting :");
for(i=0;i<n;i++)
{
	printf("%d\t",a[i]);
}
for(i=1;i<n;i++)
{
	temp = a[i];
	for(i=1;j>=0&&temp<a[j-1];j--){
	a[j] = a[j-1];
}
a[j] = temp;

printf("\n after sorting of elements :");
for(i=0;i<n;i++){
	printf("%d\t",a[i]);
}
}
}
