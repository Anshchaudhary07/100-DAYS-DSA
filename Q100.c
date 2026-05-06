//Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
//Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

// Compare function for sorting in descending order
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Create car array
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet formed
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};

    int n = sizeof(position) / sizeof(position[0]);

    printf("Number of car fleets: %d\n",
           carFleet(target, position, speed, n));

    return 0;
}