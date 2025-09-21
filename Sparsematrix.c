#include <stdio.h>
#define MAX 100

struct tuple
{
    int row;
    int col;
    int value;
} A[100], B[100], T[100], S[MAX];

// transpose of sparse matrix
void transpose()
{
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].value = A[0].value;
    int currentT = 1;
    for (int i = 0; i < A[0].col; i++)
    {
        for (int j = 1; j <= A[0].value; j++)
        {
            if (A[j].col == i)
            {
                T[currentT].row = A[j].col;
                T[currentT].col = A[j].row;
                T[currentT].value = A[j].value;
                currentT++;
            }
        }
    }
}

// adding 2 sparse matrices
void add()
{
    if (A[0].row != B[0].row || A[0].col != B[0].col)
    {
        printf("Addition not possible !! \n");
        return;
    }
    S[0].row = A[0].row;
    S[0].col = A[0].col;
    int t1 = A[0].value;
    int t2 = B[0].value;
    int i = 1, j = 1, k = 1;
    while (i <= t1 && j <= t2)
    {
        if (A[i].row == B[j].row && A[i].col == B[j].col)
        {
            S[k].row = A[i].row;
            S[k].col = A[i].col;
            S[k].value = A[i].value + B[j].value;
            i++, j++, k++;
        }
        else if ((A[i].row == B[j].row && A[i].col > B[j].col) || (A[i].col == B[j].col && A[i].row > B[j].row))
        {
            S[k].row = B[j].row;
            S[k].col = B[j].col;
            S[k].value = B[j].value;
            j++, k++;
        }
        else if ((A[i].row == B[j].row && A[i].col < B[j].col) || (A[i].col == B[j].col && A[i].row < B[j].row))
        {
            S[k].row = A[i].row;
            S[k].col = A[i].col;
            S[k].value = A[i].value;
            i++, k++;
        }
    }
    while (i < t1)
    {
        S[k].row = A[i].row;
        S[k].col = A[i].col;
        S[k].value = A[i].value;
        i++, k++;
    }
    while (j < t2)
    {
        S[k].row = B[j].row;
        S[k].col = B[j].col;
        S[k].value = B[j].value;
        j++, k++;
    }
    S[0].value = k - 1;
}

// menu driven main function
int main()
{
    int n1, n2;
    printf("Enter the no. of non-zero values in matrix A : ");
    scanf("%d", &n1);
    printf("Enter the sparse matrix A : \n");
    for (int i = 0; i <= n1; i++)
    {
        scanf("%d", &A[i].row);
        scanf("%d", &A[i].col);
        scanf("%d", &A[i].value);
    }
    printf("Enter the no. of non-zero values in matrix B : ");
    scanf("%d", &n2);
    printf("Enter the sparse matrix B : \n");
    for (int i = 0; i <= n2; i++)
    {
        scanf("%d", &B[i].row);
        scanf("%d", &B[i].col);
        scanf("%d", &B[i].value);
    }
    printf("Transpose of A: \n");
    transpose();
    for (int i = 0; i <= T[0].value; i++)
    {
        printf("%d\t%d\t%d\n", T[i].row, T[i].col, T[i].value);
    }
    printf("A + B : \n");
    add();
    for (int i = 0; i <= S[0].value; i++)
    {
        printf("%d\t%d\t%d\n", S[i].row, S[i].col, S[i].value);
    }
    return 0;
}
