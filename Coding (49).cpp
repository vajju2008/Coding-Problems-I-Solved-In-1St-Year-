#pragma GCC optimize("O3,unroll-loops") // complication hint for c++ for optimizaction and aslo expands the loop
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") // include vector extenions and bit manipulaction , quick counts the zeros from binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
const unsigned long long MOD_LARGE = 17e18; // thershold value for safer approcah
void solve() { // neither return to 0
    int N; // integers
    if (!(cin >> N)) return;
    vector<long long> X(N + 1);
    vector<int> K(N + 1);
    int max_K = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> X[i] >> K[i];
        if (K[i] > max_K) max_K = K[i];
    }
//tracking
    vector<vector<unsigned int>> dp(max_K + 1, vector<unsigned int>(max_K + 1, 0));
    for (int r = 0; r <= max_K; ++r) {
        dp[r][r] = 1;
    } // an bases case setup 
    for (int i = 1; i <= N; ++i) {
        unsigned long long x_val = X[i] % MOD;
        for (int r = 1; r <= max_K; ++r) {
            int min_c = max(0, r - i);
            for (int c = min_c; c < r; ++c) {
                unsigned long long current = dp[r][c];
                unsigned long long next_val = dp[r][c+1];
                unsigned long long weight = x_val + c; // dynamic programming to slov the sub problems 
                unsigned long long res = current + weight * next_val;
                dp[r][c] = res % MOD;
            }
        }
        long long ans = 0;
        for (int j = 0; j <= K[i]; ++j) {
            long long weight = K[i] + 1 - j;
            long long weight_sq = (weight * weight) % MOD;
            long long term = (weight_sq * dp[j][0]) % MOD;
            ans = (ans + term) % MOD;
        } // final request 
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}