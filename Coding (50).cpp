 #include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() { // never return to 0 or 1 beacuse of n integerw 
    int N;
    cin >> N;
    vector<int> A(N);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int first_odd_index = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 != 0) {
            first_odd_index = i;
            break;
        }
    }

    if (first_odd_index == -1) { // odd 
        cout << "YES" << endl;
        return;
    }

    long long suffix_sum = 0;
    for (int i = first_odd_index; i < N; i++) {
        suffix_sum += A[i];
    }

    if (suffix_sum % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}


