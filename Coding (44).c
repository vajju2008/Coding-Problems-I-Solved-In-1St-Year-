#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        int A[105];
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        char S[105];
        scanf("%s", S);

        int avail[105];
        int m = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i] == '0') {
                avail[m++] = A[i];
            }
        }

        if (m < K) {
            printf("-1\n");
        } else {
            qsort(avail, m, sizeof(int), cmp_int);
            int sum = 0;
            for (int i = 0; i < K; ++i) sum += avail[i];
            printf("%d\n", sum);
        }
    }
    return 0;
}
