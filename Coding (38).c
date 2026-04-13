#include<stdio.h>
int main()
{
	int i,key,flag=0,n;
	printf("enter array size");
	scanf("%d",&n);
	int a[n];
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	printf("enter key element");
	scanf("%d",&key);
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			flag=1;
			break;
		}
		else if(a[mid]>key)
		{
			high=mid-1;
		}
		else if(a[mid]<key)
		{
			low=mid+1;
		}
	}
		if(flag==1)
		printf("element found");
		else
		printf("not found");
	}
