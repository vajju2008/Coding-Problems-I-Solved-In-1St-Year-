#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N, S;
        scanf("%d %d", &N, &S);
        if (S <= 5 * N) {
            printf("%d\n", 6 * N);
        } else {
            printf("%d\n", 11 * N - S);
        }
    }
    return 0;
}
