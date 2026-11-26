#include <stdio.h>

int main()
{
    FILE *fp;
    int n, i, j, temp;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter at least one integer.\n");
        return 1;
    }

    int input[n];

    /* Open unsorted.txt for writing */
    fp = fopen("unsorted.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening unsorted.txt\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);

    /* Take input and write into unsorted.txt */
    for (i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        fprintf(fp, "%d ", input[i]);
    }

    fclose(fp);

    /* Read integers from unsorted.txt */
    fp = fopen("unsorted.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening unsorted.txt\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &input[i]);
    }

    fclose(fp);

    /* Bubble Sort */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (input[j] > input[j + 1])
            {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    /* Write sorted array into sorted.txt */
    fp = fopen("sorted.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening sorted.txt\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", input[i]);
    }

    fclose(fp);

    /* Display unsorted.txt */
    printf("\nElements of unsorted.txt:\n");

    fp = fopen("unsorted.txt", "r");

    while (fscanf(fp, "%d", &temp) == 1)
    {
        printf("%d ", temp);
    }

    fclose(fp);

    /* Display sorted.txt */
    printf("\n\nElements of sorted.txt:\n");

    fp = fopen("sorted.txt", "r");

    while (fscanf(fp, "%d", &temp) == 1)
    {
        printf("%d ", temp);
    }

    fclose(fp);

    printf("\n");

    return 0;
}
