#include<stdio.h>
#include<math.h>
int main(){
int x1,x2,y1,y2;
printf("enter X1 coordinate :");
scanf("%d",&x1);
printf("enter X2 coordinate :");
scanf("%d",&x2);
printf("enter Y1 coordinate :");
scanf("%d",&y1);
printf("enter Y2 coordinate :");
 scanf("%d",&y2);
 int dis = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
printf("distance between two coordinates is %d",dis);
}