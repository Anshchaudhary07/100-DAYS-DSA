#include <stdio.h>

void spiralOrder(int matrix[100][100], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        // Traverse from left to right
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];

    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    spiralOrder(matrix, rows, cols);

    return 0;
}