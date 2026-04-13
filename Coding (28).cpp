#include <stdio.h>

int main() {
    int N, i, j, temp;

    // Read the number of students
    scanf("%d", &N);

    int scores[N];

    // Read the scores
    for (i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }

    // Bubble sort with output after each iteration
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                // Swap scores[j] and scores[j + 1]
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }

        // Print the array after each outer loop iteration
        for (int k = 0; k < N; k++) {
            printf("%d ", scores[k]);
        }
        printf("\n");
    }

    return 0;
}
