#include<stdio.h>
struct dog{
       int dogage;
       char dogname[20];
       char dogbreed[20];
       char dogcolour[20];
       }*d;
       int main(){
           struct dog d1={12,"puppy","jullie","black"};
           d=&d1;
           printf("dogage=%d\n",d->dogage);
           printf("dogname=%s\n",d->dogname);
           printf("dogbreed=%s\n",d->dogbreed);
           printf("dogcolour=%s\n",d->dogcolour);
           return 0;
           }
