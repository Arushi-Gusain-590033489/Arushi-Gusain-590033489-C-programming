#include <stdio.h>

int main()
{
    FILE *fp;
    int n, num, i;
    int sum = 0, count = 0;
    float average;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Ensure at least one integer is entered
    if (n <= 0)
    {
        printf("Please enter at least one integer.\n");
        return 1;
    }

    // Open file for writing
    fp = fopen("numbers.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }

    fclose(fp);

    // Open file for reading
    fp = fopen("numbers.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }

    // Read integers and calculate sum
    while (fscanf(fp, "%d", &num) == 1)
    {
        sum = sum + num;
        count++;
    }

    fclose(fp);

    // Calculate average
    if (count > 0)
    {
        average = (float)sum / count;

        printf("\nSum = %d\n", sum);
        printf("Average = %.2f\n", average);
    }
    else
    {
        printf("No integers found in the file.\n");
    }

    return 0;
}
