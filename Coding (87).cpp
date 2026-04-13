#include<stdio.h>
struct complex
{
       float real;
       float imag;
       };
       int main()
       {
           struct complex c1={3,4,2,5};
           struct complex *ptr=&c1;
           printf("%.If",ptr->real);
           ptr->imag*=2;
           printf("%.If\n",(*ptr).imag);
           return 0;
           }
           


