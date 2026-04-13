#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests; // ballons test 
    cin >> tests;

    for (int caseNo = 0; caseNo < tests; caseNo++) {
        int size;
        cin >> size;

        long long result = 0;
        for (int idx = 0; idx < size; idx++) {
            long long value;
            cin >> value;
            result += value * (idx + 1);
        }

        cout << result;
        if (caseNo != tests - 1) cout << '\n';
    }

    return 0;
}
