// Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum = 0;
        for (int j = i; j < n; j++) {
            prefixSum += arr[j];
            if (prefixSum == 0)
                count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of zero sum subarrays: %d",
           countZeroSumSubarrays(arr, n));

    return 0;
}