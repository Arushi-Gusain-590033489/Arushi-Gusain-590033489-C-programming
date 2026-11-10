#include <stdio.h>
#include <stdlib.h>

// Function for matrix addition
void add(int *A, int *B, int *C, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(C + i * c + j) = *(A + i * c + j) + *(B + i * c + j);
}

// Function for matrix subtraction
void subtract(int *A, int *B, int *C, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(C + i * c + j) = *(A + i * c + j) - *(B + i * c + j);
}

// Function for matrix multiplication
void multiply(int *A, int *B, int *C, int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            *(C + i * c2 + j) = 0;

            for (int k = 0; k < c1; k++)
            {
                *(C + i * c2 + j) +=
                    *(A + i * c1 + k) * *(B + k * c2 + j);
            }
        }
    }
}

// Function to display matrix
void display(int *A, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", *(A + i * c + j));

        printf("\n");
    }
}

int main()
{
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Dynamic memory allocation
    int *A = (int *)malloc(r1 * c1 * sizeof(int));
    int *B = (int *)malloc(r2 * c2 * sizeof(int));

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1 * c1; i++)
        scanf("%d", A + i);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2 * c2; i++)
        scanf("%d", B + i);

    // Addition and subtraction
    if (r1 == r2 && c1 == c2)
    {
        int *C = (int *)malloc(r1 * c1 * sizeof(int));

        add(A, B, C, r1, c1);
        printf("\nAddition:\n");
        display(C, r1, c1);

        subtract(A, B, C, r1, c1);
        printf("\nSubtraction:\n");
        display(C, r1, c1);

        free(C);
    }
    else
    {
        printf("\nAddition and subtraction are not possible.\n");
    }

    // Multiplication
    if (c1 == r2)
    {
        int *C = (int *)malloc(r1 * c2 * sizeof(int));

        multiply(A, B, C, r1, c1, c2);

        printf("\nMultiplication:\n");
        display(C, r1, c2);

        free(C);
    }
    else
    {
        printf("\nMultiplication is not possible.\n");
    }

    // Release allocated memory
    free(A);
    free(B);

    return 0;
}
