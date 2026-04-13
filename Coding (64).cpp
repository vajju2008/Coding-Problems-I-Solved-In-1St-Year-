#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_mono(const string& s) {
    for (int i = 1; i < (int)s.length(); i++) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

vector<pair<int, int>> reduce_to_001(string s) {
    vector<pair<int, int>> ops;
    int n = s.length();
    while (true) {
        bool done = true;
        for (int k = 0; k < n - 1; k++) {
            if (s[k] != '0') done = false;
        }
        if (s[n - 1] != '1') done = false;
        if (done) break;

        int i = 0;
        while (i < n && s[i] == '0') i++;
        
        int j = i + 1;
        while (j < n && s[j] == '1') j++;
        
        if (j < n) {
            ops.push_back({i + 1, j + 1});
            for (int k = i; k <= j; k++) s[k] = (s[k] == '0' ? '1' : '0');
        } else {
            ops.push_back({i, n});
            for (int k = i - 1; k <= n - 1; k++) s[k] = (s[k] == '0' ? '1' : '0');
        }
    }
    return ops;
}

void solve() {
    int n; 
    if (!(cin >> n)) return;
    string A, B; 
    cin >> A >> B;
    
    if (A == B) {
        cout << "0\n0\n";
        return;
    }
    
    if (is_mono(A) && is_mono(B)) {
        cout << "1\n1\n1 " << n << "\n";
        return;
    }
    
    if (!is_mono(A) && !is_mono(B)) {
        vector<pair<int, int>> opsA = reduce_to_001(A);
        vector<pair<int, int>> opsB = reduce_to_001(B);
        
        cout << "0\n" << opsA.size() + opsB.size() << "\n";
        for (auto p : opsA) cout << p.first << " " << p.second << "\n";
        reverse(opsB.begin(), opsB.end());
        for (auto p : opsB) cout << p.first << " " << p.second << "\n";
        return;
    }
    
    if (is_mono(A) && !is_mono(B)) {
        string A_prime = A;
        for (int i = 0; i < n - 1; i++) A_prime[i] = (A_prime[i] == '0' ? '1' : '0');
        
        vector<pair<int, int>> opsA = reduce_to_001(A_prime);
        vector<pair<int, int>> opsB = reduce_to_001(B);
        
        cout << "1\n" << 1 + opsA.size() + opsB.size() << "\n";
        cout << "1 " << n - 1 << "\n";
        for (auto p : opsA) cout << p.first << " " << p.second << "\n";
        reverse(opsB.begin(), opsB.end());
        for (auto p : opsB) cout << p.first << " " << p.second << "\n";
        return;
    }
    
    if (!is_mono(A) && is_mono(B)) {
        string B_prime = B;
        for (int i = 0; i < n - 1; i++) B_prime[i] = (B_prime[i] == '0' ? '1' : '0');
        
        vector<pair<int, int>> opsA = reduce_to_001(A);
        vector<pair<int, int>> opsB = reduce_to_001(B_prime);
        
        cout << "1\n" << opsA.size() + opsB.size() + 1 << "\n";
        for (auto p : opsA) cout << p.first << " " << p.second << "\n";
        reverse(opsB.begin(), opsB.end());
        for (auto p : opsB) cout << p.first << " " << p.second << "\n";
        cout << "1 " << n - 1 << "\n";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}