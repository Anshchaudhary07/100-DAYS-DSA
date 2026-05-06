// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.

#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // Create buckets
    float buckets[n][n];   // max size n
    int count[n];

    for (int i = 0; i < n; i++)
        count[i] = 0;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index][count[index]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Concatenate all buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}