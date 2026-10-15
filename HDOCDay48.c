#include <stdio.h>

int pivot_index(int *arr, int n)
{
    int i, j;
    int leftSum, rightSum;

    for (i = 0; i < n; i++)
    {
        leftSum = 0;
        rightSum = 0;

        // Calculate left sum
        for (j = 0; j < i; j++)
        {
            leftSum = leftSum + arr[j];
        }

        // Calculate right sum
        for (j = i + 1; j < n; j++)
        {
            rightSum = rightSum + arr[j];
        }

        // Check for pivot index
        if (leftSum == rightSum)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n, i, result;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    result = pivot_index(arr, n);

    if (result == -1)
        printf("-1\n");
    else
        printf("Pivot index: %d\n", result);

    return 0;
}
