//We start with $N+1$ elements from 0 to  Our goal is to reduce this set to a single element while keeping our score as low as possible.
#include <iostream>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long k = n / 2; // to cal the pairs 
    cout << k * (k + 1) << "\n"; // sum to next number
    
}
int main() {
    // Fast Inupu and the output values 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
