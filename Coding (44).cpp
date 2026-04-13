#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long P;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= P;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % P;
        base = (base * base) % P;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, P - 2);
}

long long fact[100];
long long invFact[100];

void precompute() {
    // Only needs to be done once, but P changes per test case? 
    // The problem statement implies P is part of input, so we recompute or use max P logic.
    // Constraints say sum of N <= 35, P is large prime.
    // We will compute inside solve since P varies.
}

void solve() {
    int N;
    cin >> N >> P;

    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 2 * N + 5; i++) {
        fact[i] = (fact[i - 1] * i) % P;
        invFact[i] = modInverse(fact[i]);
    }

    long long total_NJ = 0;

    // We need to compute N(J) for J from -N+1 to 0
    for (int J = -N + 1; J <= 0; ++J) {
        // dp[i][j] stores ways to have sumA = i, sumB = j
        // We use two buffers for DP to save space and easy swap
        vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
        dp[0][0] = 1;

        for (int step = 0; step < N; ++step) {
            vector<vector<long long>> next_dp(N + 1, vector<long long>(N + 1, 0));
            vector<vector<long long>> tmp(N + 1, vector<long long>(N + 1, 0));

            // Horizontal convolution (A axis)
            // tmp[a][b] = sum(dp[a-c][b] * invFact[c])
            for (int b = 0; b <= N; ++b) {
                for (int a = 0; a <= N; ++a) {
                    if (dp[a][b] == 0) continue;
                    for (int c = 0; a + c <= N; ++c) {
                        long long term = (dp[a][b] * invFact[c]) % P;
                        tmp[a + c][b] = (tmp[a + c][b] + term) % P;
                    }
                }
            }

            // Vertical convolution (B axis)
            // next_dp[a][b] = sum(tmp[a][b-e] * invFact[e])
            // Apply constraint: a - b >= J
            for (int a = 0; a <= N; ++a) {
                for (int b = 0; b <= N; ++b) {
                    if (tmp[a][b] == 0) continue;
                    for (int e = 0; b + e <= N; ++e) {
                        int next_b = b + e;
                        // Check constraint: S_k >= J implies a - next_b >= J
                        if (a - next_b >= J) {
                            long long term = (tmp[a][b] * invFact[e]) % P;
                            next_dp[a][next_b] = (next_dp[a][next_b] + term) % P;
                        }
                    }
                }
            }
            dp = next_dp;
        }

        long long ways = (dp[N][N] * fact[N]) % P;
        ways = (ways * fact[N]) % P;
        total_NJ = (total_NJ + ways) % P;
    }

    // Formula: Ans = -N * (-N * Total + Sum(N(J)))
    // Total pairs = N^(2N)
    
    long long total_pairs = power(N, 2 * N);
    long long term1 = (total_pairs * (P - N)) % P; // -N * Total
    
    long long sum_min = (term1 + total_NJ) % P;
    
    long long ans = (sum_min * (P - N)) % P; // -N * sum_min
    
    cout << ans << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}