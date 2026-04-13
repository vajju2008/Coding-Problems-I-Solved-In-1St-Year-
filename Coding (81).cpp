// The core of this problem lies in simplifying the operation used to calculate the score f(B) 
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long base, long long exp) { // 10 to the power 9 + 7
    long long res = 1;
    base %= MOD;
    while (exp > 0) { // binary exponentationation
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
void solve() {
    long long n, m; // two integers readss
    cin >> n >> m;
    long long sum_m = (m * (m + 1)) % MOD;
    long long inv2 = 500000004; // modulars inverses of 2 mod 
    long long sum_1_to_m = (sum_m * inv2) % MOD;
    long long m_pow_n_minus_1 = power(m, n - 1);
    long long part1 = (n * m_pow_n_minus_1) % MOD;
    part1 = (part1 * sum_1_to_m) % MOD; // part1 - part2 
    long long part2 = 0;
    for (int j = 1; j <= m; ++j) {
        part2 = (part2 + power(j, n)) % MOD;
    }
    long long ans = (part1 - part2 + MOD) % MOD;
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}