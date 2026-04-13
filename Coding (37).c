#include <stdio.h>

int main() {
    int n, target, left, right, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    left = 0;
    right = n - 1;
    mid = 0;
    int found = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = 1;
            printf("Element found at index %d\n", mid);
            break;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found in the array\n");
    }

    return 0;
}
