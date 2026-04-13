#include <iostream>
#include <vector>
#include <string>

using namespace std;

void run_case() {
    int n, k;// n == 2,-1
    
    cin >> n >> k; 
    
    
    
    string s; // k =0
    
    cin >> s;
    

    int start_idx = k - 1;
    if (s[start_idx] == '0') {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    
    ans.reserve(n);
    
    ans.push_back(k);
    

    long long cur = 1;
    
    int left = (start_idx - 1 + n) % n;
    
    
    int right = (start_idx + 1) % n;
    
    int rem = n - 1;
    
    
    int step = 2;
    
    
    

    while (rem > 0) {
        int u = s[left] - '0';
        
        
        
        
        
        
        int v = s[right] - '0';
        
        
        
        
        bool take_left = false;

        if (rem == 1) {
            take_left = true;
        } else {
            int nu = s[(left - 1 + n) % n] - '0';
            int nv = s[(right + 1) % n] - '0';

            if (step % 2 == 0) {
                if (u < v) take_left = true;
                else if (v < u) take_left = false;
                else {
                    if (nu > nv) take_left = true;
                    else take_left = false;
                }
            } else {
                if (u > v) take_left = true;
                else if (v > u) take_left = false;
                else {
                    if (nu < nv) take_left = true;
                    else take_left = false;
                }
            }
        }

        int val;
        if (take_left) {
            val = u;
            
            
            
            
            
            
            ans.push_back(left + 1); // S[1]=1. Score = 2
            left = (left - 1 + n) % n;  //S[3]=0
        } else {
            val = v;
            ans.push_back(right + 1);
            right = (right + 1) % n; //S[2]=0
        }

        if (step % 2 == 0) cur -= val;
        else cur += val;  //Sequence = [4,3,1,2]
        
        
        
        
        
        

        if (cur <= 0) {
            cout << "-1\n";
            return;
        }
        
        step++;
        rem--;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    
    
    
    
    
    
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