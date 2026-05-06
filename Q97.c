//Problem: Given meeting intervals, find minimum number of rooms required.
//Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting by start time
int compareStart(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Compare function for sorting end times
int compareEnd(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(Interval intervals[], int n) {
    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), compareStart);

    int *endTimes = (int *)malloc(n * sizeof(int));
    int size = 0; // number of rooms used

    for (int i = 0; i < n; i++) {
        // Step 2: Check if any room can be reused
        int reused = 0;

        for (int j = 0; j < size; j++) {
            if (intervals[i].start >= endTimes[j]) {
                // reuse this room
                endTimes[j] = intervals[i].end;
                reused = 1;
                break;
            }
        }

        // Step 3: If no room reused → add new room
        if (!reused) {
            endTimes[size++] = intervals[i].end;
        }

        // Keep endTimes sorted
        qsort(endTimes, size, sizeof(int), compareEnd);
    }

    free(endTimes);
    return size;
}

int main() {
    Interval intervals[] = {{0,30}, {5,10}, {15,20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int rooms = minMeetingRooms(intervals, n);

    printf("Minimum rooms required: %d\n", rooms);
    return 0;
}