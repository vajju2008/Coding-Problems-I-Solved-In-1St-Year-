//At first glance, this problem looks like it requires an active simulation of everyndividual balloon throw. Howeve simulatingz it sbs  would result in an O(N*2)$ time complexity leading to a Time Limit Exceeded error given  \times 105
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int s = 0; // Global counter for balloons thrown
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= s) { // Friend left early
            cout << a << " ";
        } else { // Friend present in the pary
            cout << s << " ";
            s++;
        }
    }
    cout << "\n";
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