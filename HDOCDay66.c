#include <stdio.h>

#define MAX 10

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
int n;

// Recursively calculate one element C[i][j]
int multiplyElement(int i, int j, int k)
{
    if (k == n)
        return 0;

    return A[i][k] * B[k][j] + multiplyElement(i, j, k + 1);
}

// Recursively calculate all elements of matrix C
void multiplyMatrix(int i, int j)
{
    if (i == n)
        return;

    C[i][j] = multiplyElement(i, j, 0);

    if (j + 1 < n)
        multiplyMatrix(i, j + 1);
    else
        multiplyMatrix(i + 1, 0);
}

int main()
{
    int i, j;

    printf("Enter the order of square matrices: ");
    scanf("%d", &n);

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiplyMatrix(0, 0);

    printf("Product matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}
