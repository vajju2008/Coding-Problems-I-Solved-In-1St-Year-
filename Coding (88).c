#include <stdio.h>

int main() {
    long long N;
    
    // Reading the input N
    if (scanf("%lld", &N) == 1) {
        
        // Checking if N is a multiple of 3
        if (N % 3 == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}