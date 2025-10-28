#include <stdio.h>
#define MAX 100

struct tuple {
    int row;
    int col;
    int value;
} A[MAX], B[MAX], T[MAX], S[MAX];

// Transpose of sparse matrix A
void transpose() {
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].value = A[0].value;

    int currentT = 1;
    for (int i = 0; i < A[0].col; i++) {
        for (int j = 1; j <= A[0].value; j++) {
            if (A[j].col == i) {
                T[currentT].row = A[j].col;
                T[currentT].col = A[j].row;
                T[currentT].value = A[j].value;
                currentT++;
            }
        }
    }
}

// Add two sparse matrices A and B into S
void add() {
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        printf("Addition not possible!\n");
        return;
    }

    S[0].row = A[0].row;
    S[0].col = A[0].col;

    int i = 1, j = 1, k = 1;
    int t1 = A[0].value;
    int t2 = B[0].value;

    while (i <= t1 && j <= t2) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            S[k].row = A[i].row;
            S[k].col = A[i].col;
            S[k].value = A[i].value + B[j].value;
            i++; j++; k++;
        } else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            S[k].row = A[i].row;
            S[k].col = A[i].col;
            S[k].value = A[i].value;
            i++; k++;
        } else {
            S[k].row = B[j].row;
            S[k].col = B[j].col;
            S[k].value = B[j].value;
            j++; k++;
        }
    }

    while (i <= t1) {
        S[k].row = A[i].row;
        S[k].col = A[i].col;
        S[k].value = A[i].value;
        i++; k++;
    }

    while (j <= t2) {
        S[k].row = B[j].row;
        S[k].col = B[j].col;
        S[k].value = B[j].value;
        j++; k++;
    }

    S[0].value = k - 1;
}

int main() {
    printf("Enter total rows, cols, and number of non-zero elements for A: ");
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].value);
    printf("Enter the non-zero elements of A (row col value):\n");
    for (int i = 1; i <= A[0].value; i++)
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);

    printf("Enter total rows, cols, and number of non-zero elements for B: ");
    scanf("%d %d %d", &B[0].row, &B[0].col, &B[0].value);
    printf("Enter the non-zero elements of B (row col value):\n");
    for (int i = 1; i <= B[0].value; i++)
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);

    printf("\nTranspose of A:\n");
    transpose();
    for (int i = 0; i <= T[0].value; i++)
        printf("%d\t%d\t%d\n", T[i].row, T[i].col, T[i].value);

    printf("\nA + B:\n");
    add();
    for (int i = 0; i <= S[0].value; i++)
        printf("%d\t%d\t%d\n", S[i].row, S[i].col, S[i].value);

    return 0;
}
