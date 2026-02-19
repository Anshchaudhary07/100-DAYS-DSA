// Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    
    int minSum = INT_MAX;
    int minLeft = left, minRight = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = left;
            minRight = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements closest to zero are: %d and %d\n",
           arr[minLeft], arr[minRight]);
    printf("Their sum is: %d\n", minSum);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    findClosestToZero(arr, n);
    return 0;
}