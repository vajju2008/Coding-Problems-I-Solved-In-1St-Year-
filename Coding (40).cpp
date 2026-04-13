#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;
    
    vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int winning_trades = 0;
    
    // Track the best entry points for the current segment from the rug puul 
    long long current_min = P[0];
    long long current_max = P[0];

    for (int i = 1; i < N; i++) {
       
        long long buy_sell_profit = P[i] - current_min - K;
        long long sell_buy_profit = current_max - P[i] - K;

        if (buy_sell_profit > 0 || sell_buy_profit > 0) {
            winning_trades++;

            if (i + 1 < N) {
                current_min = P[i+1];
                current_max = P[i+1];
                i++; 
            } else {
                break; // the code break with max n min
            }
        } else {

            current_min = min(current_min, P[i]);
            current_max = max(current_max, P[i]);
        }
    }
    
    cout << winning_trades << endl;
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