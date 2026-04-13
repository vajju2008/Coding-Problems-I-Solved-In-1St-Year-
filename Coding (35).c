#include<stdio.h>
int main()
{
	int i,flag=0,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int low=0,high=n-1,mid=0,key;
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		mid=(high+low)/2;
		if(a[mid]==key)
		{
			flag=1;
			break;
		}
		else if (a[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(flag==1)
	{
		printf("element found");
	}
	else
	{
		printf("element not found");
	}
}