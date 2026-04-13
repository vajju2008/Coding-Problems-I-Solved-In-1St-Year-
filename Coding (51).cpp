#include <iostream>

using namespace std;
void solve() {
    long long A, B, C;
    cin >> A >> B >> C;
    
    if (C % 3 == 0 && B == (2 * A) + (C / 3)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
//Let  be the total number of Type 1 operations.Let  be the total number of Type 2 operations.