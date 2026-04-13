#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) implementation
struct BIT {
    int size;
    vector<int> data;

    BIT(int n) : size(n), data(n + 1, 0) {}

    // Add val to element at idx
    void update(int idx, int val) {
        for (++idx; idx <= size; idx += idx & -idx)
            data[idx] += val;
    }

    // Return sum from 0 to idx
    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += data[idx];
        return res;
    }
    
    // Return sum from l to r
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r + 1) - query(l);
    }
};

// Check if a given k is valid
bool check(long long k, int n, const vector<int>& a, const vector<int>& c, int mn, int mx) {
    BIT ft(c.size());
    
    // Iterate through the array looking for a "bad" right-side element a[j]
    for (int x : a) {
        // Condition: If current element x is small enough that it can't swap with Min
        if (x < mn + k) {
            // We need to check if there is a previous element 'y' (a[i]) such that:
            // 1. y > x (Inversion)
            // 2. y < x + k (Close to x)
            // 3. y > mx - k (Close to Max)
            
            // This defines a range [lower_limit, upper_limit) for y
            long long lower_limit = max((long long)x, (long long)mx - k); // Must be > mx - k AND > x
            long long upper_limit = x + k;
            
            // Find the indices in the compressed array 'c'
            int l_idx = upper_bound(c.begin(), c.end(), lower_limit) - c.begin();
            int r_idx = lower_bound(c.begin(), c.end(), upper_limit) - c.begin() - 1;
            
            // If such a y exists in the BIT, this k is invalid
            if (l_idx <= r_idx) {
                if (ft.query(l_idx, r_idx) > 0) return false;
            }
        }
        
        // Add current element x to the BIT for future checks
        int pos = lower_bound(c.begin(), c.end(), x) - c.begin();
        ft.update(pos, 1);
    }
    return true;
}

void run_case() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    int mn = 2e9, mx = -2e9;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }

    // Check if already sorted
    bool sorted = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << -1 << "\n";
        return;
    }

    // Coordinate Compression for BIT
    vector<int> c = a;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    // Binary Search for Answer
    long long l = 1, r = 1e9, ans = 0;
    
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid, n, a, c, mn, mx)) {
            ans = mid;
            l = mid + 1; // Try larger k
        } else {
            r = mid - 1; // Try smaller k
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
    return 0;
}