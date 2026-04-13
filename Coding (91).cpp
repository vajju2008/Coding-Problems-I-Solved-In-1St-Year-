#include<stdio.h>
int main ()--
{
 int a[100],i,n,temp,p;
 scanf("%d",&n);
 printf("\n enter elements into array");
 for (i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
     }
     for(p=1;p<n;p++)
     {
                     for(i=o,i<n-p;i++)
                     {
                      if(a[i]>a(i+1))
                      {
                        temp=a[i]
                        a[i]=a[i+i];
                        a[i+i]=temp;
                        }
                        }
                        }
                        printf("\n after sorting the array elements are");
                        for(i=0;i<n;i++)
                        {
                          printf("%d/t",a[i]);
                          }
                           return 0;
                           }
