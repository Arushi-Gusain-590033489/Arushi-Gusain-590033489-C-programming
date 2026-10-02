#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInteger(char str[])
{
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i = 1;

    if (str[i] == '\0')
        return 0;

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;

        i++;
    }

    return 1;
}

void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

double findAverage(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + a[i];

    return (double)sum / n;
}

double findMedian(int a[], int n)
{
    if (n % 2 == 0)
        return (a[n / 2 - 1] + a[n / 2]) / 2.0;
    else
        return a[n / 2];
}

int main(int argc, char *argv[])
{
    int a[100];
    int n = 0;

    for (int i = 1; i < argc; i++)
    {
        if (isInteger(argv[i]))
        {
            a[n] = atoi(argv[i]);
            n++;
        }
        else
        {
            printf("Invalid argument ignored: %s\n", argv[i]);
        }
    }

    if (n == 0)
    {
        printf("No valid integers entered.\n");
        return 0;
    }

    sort(a, n);

    printf("Valid integers in ascending order: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    printf("Minimum: %d\n", a[0]);
    printf("Maximum: %d\n", a[n - 1]);
    printf("Average: %.2f\n", findAverage(a, n));
    printf("Median: %.2f\n", findMedian(a, n));

    int secondLargestFound = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] != a[n - 1])
        {
            printf("Second-largest distinct value: %d\n", a[i]);
            secondLargestFound = 1;
            break;
        }
    }

    if (!secondLargestFound)
        printf("Second-largest distinct value does not exist.\n");

    return 0;
}
