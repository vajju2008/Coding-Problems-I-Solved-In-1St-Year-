#include <stdio.h>
#include <math.h>   // f

int main() {
    long long n, temp, sum = 0;   
    int digits = 0;


    scanf("%lld", &n);

    temp = n;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = n; 


    while (temp > 0) {
        int digit = temp % 10;                 
        sum += (long long)pow(digit, digits);  
        temp /= 10;                            
    }

    // Compare sum with original number
    if (sum == n)
        printf("Armstrong\n");
    else
        printf("Not Armstrong\n");

    return 0;
}
