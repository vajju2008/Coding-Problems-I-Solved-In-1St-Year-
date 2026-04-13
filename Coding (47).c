#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int happy = M - N;
    if (happy < 0)
        happy = 0;
    if (happy > N)
        happy = N;

    printf("%d\n", happy);
    return 0;
}
