#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int get_diff(const string& a, const string& b) {
    int d = 0;
    if (a[0] != b[0]) d++;
    int n = a.length();
    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] != a[i + 1]) != (b[i] != b[i + 1])) d++;
    }
    if (a[n - 1] != b[n - 1]) d++;
    return d;
}

vector<pair<int, int>> find_shortest_0_cost(string start_A, const string& B, int n) {
    int initial_dist = get_diff(start_A, B);
    if (initial_dist == 0) return {};

    queue<pair<string, vector<pair<int, int>>>> q;
    unordered_set<string> vis;

    q.push({start_A, {}});
    vis.insert(start_A);

    while (!q.empty()) {
        auto front = q.front();
        string u = front.first;
        vector<pair<int, int>> path = front.second;
        q.pop();

        if (path.size() > 6) continue;

        for (int L = 0; L < n; ++L) {
            for (int R = L; R < n; ++R) {
                if (u[L] != u[R]) {
                    string v = u;
                    for (int i = L; i <= R; ++i) {
                        v[i] = (v[i] == '0' ? '1' : '0');
                    }

                    if (vis.find(v) == vis.end()) {
                        vis.insert(v);
                        vector<pair<int, int>> next_path = path;
                        next_path.push_back({L + 1, R + 1});

                        if (get_diff(v, B) < initial_dist) {
                            return next_path;
                        }
                        q.push({v, next_path});
                    }
                }
            }
        }
    }
    return {{-1, -1}};
}

vector<pair<int, int>> try_reach(string curr_A, const string& B, int n) {
    vector<pair<int, int>> total_path;
    while (curr_A != B) {
        vector<pair<int, int>> path = find_shortest_0_cost(curr_A, B, n);
        if (!path.empty() && path[0].first == -1) {
            return {{-1, -1}};
        }
        for (auto op : path) {
            for (int i = op.first - 1; i < op.second; ++i) {
                curr_A[i] = (curr_A[i] == '0' ? '1' : '0');
            }
            total_path.push_back(op);
        }
    }
    return total_path;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    string A, B;
    cin >> A >> B;

    if (A == B) {
        cout << 0 << "\n" << 0 << "\n";
        return;
    }

    string curr_A = A;
    vector<pair<int, int>> ops_0;
    bool stuck = false;

    while (curr_A != B) {
        vector<pair<int, int>> path = find_shortest_0_cost(curr_A, B, n);
        if (!path.empty() && path[0].first == -1) {
            stuck = true;
            break;
        }
        for (auto op : path) {
            for (int i = op.first - 1; i < op.second; ++i) {
                curr_A[i] = (curr_A[i] == '0' ? '1' : '0');
            }
            ops_0.push_back(op);
        }
    }

    if (!stuck && curr_A == B) {
        cout << 0 << "\n" << ops_0.size() << "\n";
        for (auto op : ops_0) {
            cout << op.first << " " << op.second << "\n";
        }
        return;
    }

    bool found = false;
    for (int L = 0; L < n; ++L) {
        if (found) break;
        for (int R = L; R < n; ++R) {
            if (curr_A[L] == curr_A[R]) {
                string next_A = curr_A;
                for (int i = L; i <= R; ++i) {
                    next_A[i] = (next_A[i] == '0' ? '1' : '0');
                }

                vector<pair<int, int>> path_from_next = try_reach(next_A, B, n);
                
                if (path_from_next.empty() || path_from_next[0].first != -1) {
                    vector<pair<int, int>> final_ops = ops_0;
                    final_ops.push_back({L + 1, R + 1});
                    for (auto op : path_from_next) final_ops.push_back(op);

                    cout << 1 << "\n" << final_ops.size() << "\n";
                    for (auto op : final_ops) {
                        cout << op.first << " " << op.second << "\n";
                    }
                    found = true;
                    break;
                }
            }
        }
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