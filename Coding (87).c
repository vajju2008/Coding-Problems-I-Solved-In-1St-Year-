#include <stdio.h>

// Function to solve a single test case
void solve() {
    int n, k;
    // Read two integers from input
    scanf("%d %d", &n, &k);

    // Calculate total time in minutes 60 
    int total_minutes = n * k;

    // Convert total minutes to hours and remaining minutes 60 
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;

    // Print the result followed by a new line so it will not get errors
    printf("%d %d\n", hours, minutes);
}

int main() {
    int t;
    // Read the number of test cases t 
    scanf("%d", &t);

    // Loop through each test case t--
    while (t--) {
        solve();
    }

    return 0;
}