// Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number of rotations: ");
    scanf("%d", &k);
    k = k % n;
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    for(int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
    printf("Array after rotation:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}