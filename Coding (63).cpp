#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

using namespace std;

uint64_t get_D(const string& A) {
    uint64_t d = 0;
    if (A[0] == '1') d |= 1ULL;
    for (int i = 0; i < A.length() - 1; ++i) {
        if (A[i] != A[i+1]) d |= (1ULL << (i + 1));
    }
    if (A.back() == '1') d |= (1ULL << A.length());
    return d;
}

bool is_mono(const string& s) {
    return (s.find('0') == string::npos || s.find('1') == string::npos);
}

struct State {
    uint64_t mask;
    int steps;
    int h;
    bool operator<(const State& o) const {
        if (steps + h != o.steps + o.h) return steps + h > o.steps + o.h;
        return h > o.h; 
    }
};

vector<pair<int, int>> solve_0_cost(uint64_t start, uint64_t target, int N) {
    if (start == target) return {};
    
    priority_queue<State> pq;
    unordered_map<uint64_t, pair<uint64_t, pair<int, int>>> parent;
    
    pq.push({start, 0, (int)__builtin_popcountll(start ^ target) / 2});
    parent[start] = {start, {-1, -1}};
    
    int expanded = 0;
    while (!pq.empty()) {
        auto [u, steps, h] = pq.top(); pq.pop();
        
        if (u == target) {
            vector<pair<int, int>> path;
            uint64_t curr = target;
            while (curr != start) {
                auto p = parent[curr];
                path.push_back(p.second);
                curr = p.first;
            }
            reverse(path.begin(), path.end());
            return path;
        }
        
        if (expanded++ > 80000) break; 
        
        for (int i = 0; i < N; ++i) {
            uint64_t current_pop = 0;
            for (int j = i + 1; j <= N; ++j) {
                if (j > i + 1) {
                    if ((u >> (j - 1)) & 1) current_pop++;
                }
                if (current_pop % 2 == 1) {
                    uint64_t v = u ^ (1ULL << i) ^ (1ULL << j);
                    if (parent.find(v) == parent.end()) {
                        parent[v] = {u, {i + 1, j}};
                        pq.push({v, steps + 1, (int)__builtin_popcountll(v ^ target) / 2});
                    }
                }
            }
        }
    }
    return {{-1, -1}};
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
    
    bool monoA = is_mono(A);
    bool monoB = is_mono(B);
    
    if (!monoA && !monoB) {
        auto path = solve_0_cost(get_D(A), get_D(B), n);
        cout << "0\n" << path.size() << "\n";
        for (auto p : path) cout << p.first << " " << p.second << "\n";
        return;
    }
    
    if (monoA) {
        uint64_t best_A_prime_D = 0;
        pair<int, int> best_op = {-1, -1};
        int min_diff = 1000;
        uint64_t target_D = get_D(B);
        
        for (int L = 1; L <= n; ++L) {
            for (int R = L; R <= n; ++R) {
                if (A[L-1] == A[R-1]) { 
                    string A_prime = A;
                    for(int i = L-1; i <= R-1; ++i) A_prime[i] = (A_prime[i] == '0' ? '1' : '0');
                    if (A_prime == B) { 
                        cout << "1\n1\n" << L << " " << R << "\n";
                        return;
                    }
                    if (!is_mono(A_prime)) {
                        uint64_t D_prime = get_D(A_prime);
                        int diff = __builtin_popcountll(D_prime ^ target_D);
                        if (diff < min_diff) {
                            min_diff = diff;
                            best_A_prime_D = D_prime;
                            best_op = {L, R};
                        }
                    }
                }
            }
        }
        
        auto path = solve_0_cost(best_A_prime_D, target_D, n);
        cout << "1\n" << 1 + path.size() << "\n";
        cout << best_op.first << " " << best_op.second << "\n";
        for (auto p : path) cout << p.first << " " << p.second << "\n";
    } else { 
        uint64_t best_B_prime_D = 0;
        pair<int, int> best_op = {-1, -1};
        int min_diff = 1000;
        uint64_t start_D = get_D(A);
        
        for (int L = 1; L <= n; ++L) {
            for (int R = L; R <= n; ++R) {
                if (B[L-1] == B[R-1]) { 
                    string B_prime = B;
                    for(int i = L-1; i <= R-1; ++i) B_prime[i] = (B_prime[i] == '0' ? '1' : '0');
                    if (!is_mono(B_prime)) {
                        uint64_t D_prime = get_D(B_prime);
                        int diff = __builtin_popcountll(start_D ^ D_prime);
                        if (diff < min_diff) {
                            min_diff = diff;
                            best_B_prime_D = D_prime;
                            best_op = {L, R}; 
                        }
                    }
                }
            }
        }
        
        auto path = solve_0_cost(start_D, best_B_prime_D, n);
        cout << "1\n" << path.size() + 1 << "\n";
        for (auto p : path) cout << p.first << " " << p.second << "\n";
        cout << best_op.first << " " << best_op.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}