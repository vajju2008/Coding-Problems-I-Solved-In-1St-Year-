#include<stdio.h>
int main()   
{
    int n=5,i,j,temp;
    int a[n];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
       {
         scanf("%d",&a[n]);
       }
    }  
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
       {
         a[j]>a[j+1];
         temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
       }
    }
    for(i=0;i<n;i++)
    {   
      for(j=0;j<n;j++) 
       {
          printf("%d",a[j]);
       }
    }
return 0;
}  
