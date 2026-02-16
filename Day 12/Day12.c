#include <stdio.h>

int main() {
    int n, m;
    int matrix[100][100];
    int i, j;
    int isSymmetric = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);

    // Check square matrix
    if (n != m) {
        printf("Matrix is not symmetric (Not square matrix)\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    if (isSymmetric)
        printf("Matrix is symmetric\n");
    else
        printf("Matrix is not symmetric\n");

    return 0;
}