#include <stdio.h>

void solve() {
    int W, P, K;
    if (scanf("%d %d %d", &W, &P, &K) != 3) {
        return;
    }

    int total_stylishness = 0;
    int wooden_to_buy = 0;
    int plastic_to_buy = 0;

    if (K < W) {
        wooden_to_buy = K;
    } else {
        wooden_to_buy = W;
    }

    total_stylishness = wooden_to_buy * 2;

    int remaining_chairs = K - wooden_to_buy;

    plastic_to_buy = remaining_chairs;
    
    total_stylishness = total_stylishness + (plastic_to_buy * 1);

    printf("%d\n", total_stylishness);
}

int main() {
    int T;
    
    if (scanf("%d", &T) != 1) {
        return 1;
    }

    while (T--) {
        solve();
    }

    return 0;
}