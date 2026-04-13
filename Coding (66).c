#include <stdio.h>
#include <math.h>

int main() {
    
    int X;  // Ranks of the chess tourment
   
    scanf("%d", &X);

    int prize = 1000 * (int)pow(2, 4 - X);

    printf("%d\n", prize);
    return 0;
}
