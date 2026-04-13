#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int final_position;
        if (N % 2 == 0) {
            // If N is even, the final position is N/2.
            final_position = N / 2;
        } else {
            // If N is odd, the final position is (N+1)/2.
            final_position = (N + 1) / 2;
        }
        printf("%d\n", final_position);
    }
    return 0;
}