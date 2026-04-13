#include <stdio.h>

// This function handles the logic for a single test case.
void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Declare a character array to store the string.
    // Size 101 is safe since the max length is 100 (+1 for null terminator).
    char s[101]; 
    scanf("%s", s);

    // Condition 1: A draw is impossible if the total number of matches is odd.
    if (n % 2 != 0) {
        printf("No\n");
        return;
    }

    // Count Alice's current wins (number of '1's).
    int alice_score = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') {
            alice_score++;
        }
    }
    
    // Calculate Bob's score and the target score for a draw.
    int bob_score = m - alice_score;
    int target_score = n / 2;

    // Condition 2: Check if it's still possible for both players to reach the target score.
    // This is true only if neither has already surpassed it. only target_score
    if (alice_score <= target_score && bob_score <= target_score) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    int t;
    // Read the number of test cases.
    scanf("%d", &t);
    // Loop through each test case.
    while (t--) {
        solve();
    }
    return 0;
}