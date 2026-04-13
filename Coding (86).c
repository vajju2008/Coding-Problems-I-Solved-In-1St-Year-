#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    

    int toys_cost = 200 * N;
    
    int tv_cost = 1000;
    

    // Minimum cost
    if (toys_cost < tv_cost)
    
        printf("%d\n", toys_cost);
        
    else
        printf("%d\n", tv_cost);
        

    return 0;
}