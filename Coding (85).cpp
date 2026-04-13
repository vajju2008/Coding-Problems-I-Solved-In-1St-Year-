#include<stdio.h>
#define n 5
int main(){
 	int a[n]={22, 4, 81, 9,23};
 	int i,j,temp;
 	for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
		 {
	 			if(a[j]>a[j+1])
				 {
	 					temp = a[j];
	 					a[j] = a[j+1];
	 					a[j+1] = temp;
		 		}
	 	}
	}
	 for(int i=0;i<n;i++)
	 	printf("%d  ",a[i]);
	 return 0;
 }