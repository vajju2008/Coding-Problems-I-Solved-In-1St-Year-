#include <iostream>

#include <vector>

#include <algorithm>


using namespace std;

void solve() {
    
    int n;
    
    cin >> n;
    

    vector<int> numbers(n);
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int minSum = numbers[0] + numbers[1];

    for (int i = 0; i < n - 1; i++) {
        int currentSum = numbers[i] + numbers[i + 1];
        if (currentSum < minSum) {
            
            minSum = currentSum;
        }
    }

    cout << minSum << endl;
}

int main() {
    int testCases; // rad all the read tesr cases 
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}