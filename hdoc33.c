#include <stdio.h>

void addition()
{
    int A[10][10], B[10][10], C[10][10];
    int L[10][10], R[10][10];
    int m, n, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter matrix A:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    printf("Enter matrix C:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &C[i][j]);

    /* (A+B)+C and A+(B+C) */
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            L[i][j] = (A[i][j] + B[i][j]) + C[i][j];
            R[i][j] = A[i][j] + (B[i][j] + C[i][j]);
        }
    }

    printf("\n(A+B)+C:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", L[i][j]);
        printf("\n");
    }

    printf("\nA+(B+C):\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }

    printf("\nAssociative property of addition is verified.\n");
}


void multiplication()
{
    int A[10][10], B[10][10], C[10][10];
    int AB[10][10], BC[10][10];
    int L[10][10], R[10][10];
    int m, n, p, q, i, j, k;

    printf("Enter m n p q: ");
    scanf("%d%d%d%d", &m, &n, &p, &q);

    printf("Enter matrix A:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    printf("Enter matrix C:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < q; j++)
            scanf("%d", &C[i][j]);

    /* AB = A x B */
    for(i = 0; i < m; i++)
        for(j = 0; j < p; j++)
        {
            AB[i][j] = 0;
            for(k = 0; k < n; k++)
                AB[i][j] += A[i][k] * B[k][j];
        }

    /* L = (A x B) x C */
    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++)
        {
            L[i][j] = 0;
            for(k = 0; k < p; k++)
                L[i][j] += AB[i][k] * C[k][j];
        }

    /* BC = B x C */
    for(i = 0; i < n; i++)
        for(j = 0; j < q; j++)
        {
            BC[i][j] = 0;
            for(k = 0; k < p; k++)
                BC[i][j] += B[i][k] * C[k][j];
        }

    /* R = A x (B x C) */
    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++)
        {
            R[i][j] = 0;
            for(k = 0; k < n; k++)
                R[i][j] += A[i][k] * BC[k][j];
        }

    printf("\n(A x B) x C:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
            printf("%d ", L[i][j]);
        printf("\n");
    }

    printf("\nA x (B x C):\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }

    printf("\nAssociative property of multiplication is verified.\n");
}


int main()
{
    int choice;

    do
    {
        printf("\n1. Matrix Addition");
        printf("\n2. Matrix Multiplication");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addition();
                break;

            case 2:
                multiplication();
                break;

            case 3:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3);

    return 0;
}
