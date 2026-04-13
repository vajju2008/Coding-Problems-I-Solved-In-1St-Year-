#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void solve() {
    int N; // length of the letter s in the banneer
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    vector<int> counts(26, 0);

    for (char c : S) {
        if (islower(c)) {
            counts[c - 'a']++;
        } else {
            counts[c - 'A']++;
        }
    }

    
    sort(counts.rbegin(), counts.rend());

    
    cout << counts[0] + counts[1] << endl;
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