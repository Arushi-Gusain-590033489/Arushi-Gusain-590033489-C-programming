#include <stdio.h>

void leftProperty()
{
    int A[10][10], B[10][10], C[10][10];
    int L[10][10], R[10][10];
    int m, n, p, i, j, k;

    printf("Enter m n p: ");
    scanf("%d%d%d", &m, &n, &p);

    printf("Enter matrix A:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for(i=0; i<n; i++)
        for(j=0; j<p; j++)
            scanf("%d", &B[i][j]);

    printf("Enter matrix C:\n");
    for(i=0; i<n; i++)
        for(j=0; j<p; j++)
            scanf("%d", &C[i][j]);

    /* A*(B+C) and (A*B)+(A*C) */
    for(i=0; i<m; i++)
    {
        for(j=0; j<p; j++)
        {
            L[i][j] = 0;
            R[i][j] = 0;

            for(k=0; k<n; k++)
            {
                L[i][j] += A[i][k] * (B[k][j] + C[k][j]);

                R[i][j] += (A[i][k] * B[k][j])
                         + (A[i][k] * C[k][j]);
            }
        }
    }

    printf("\nA*(B+C):\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<p; j++)
            printf("%d ", L[i][j]);
        printf("\n");
    }

    printf("\n(A*B)+(A*C):\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<p; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }

    printf("\nLeft distributive property is verified.\n");
}


void rightProperty()
{
    int A[10][10], B[10][10], C[10][10];
    int L[10][10], R[10][10];
    int m, n, p, i, j, k;

    printf("Enter m n p: ");
    scanf("%d%d%d", &m, &n, &p);

    printf("Enter matrix A:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &B[i][j]);

    printf("Enter matrix C:\n");
    for(i=0; i<n; i++)
        for(j=0; j<p; j++)
            scanf("%d", &C[i][j]);

    /* (A+B)*C and (A*C)+(B*C) */
    for(i=0; i<m; i++)
    {
        for(j=0; j<p; j++)
        {
            L[i][j] = 0;
            R[i][j] = 0;

            for(k=0; k<n; k++)
            {
                L[i][j] += (A[i][k] + B[i][k]) * C[k][j];

                R[i][j] += (A[i][k] * C[k][j])
                         + (B[i][k] * C[k][j]);
            }
        }
    }

    printf("\n(A+B)*C:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<p; j++)
            printf("%d ", L[i][j]);
        printf("\n");
    }

    printf("\n(A*C)+(B*C):\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<p; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }

    printf("\nRight distributive property is verified.\n");
}


int main()
{
    int choice;

    do
    {
        printf("\n1. Left Distributive Property");
        printf("\n2. Right Distributive Property");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                leftProperty();
                break;

            case 2:
                rightProperty();
                break;

            case 3:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);

    return 0;
}
