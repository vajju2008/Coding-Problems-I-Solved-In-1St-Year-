// three a,b,c 
#include <iostream>

#include <algorithm>
using namespace std;
void solve() { // nevers return to 0 
    int n;
    cin >> n;
    int ans = 1000; 
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ans = max(a, min(ans, b));
    }
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false); // operation flase
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}