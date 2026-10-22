#include <stdio.h>

int max_subarray_sum(int *arr, int size, int k)
{
    // Check if k is invalid
    if (k <= 0 || k >= size)
        return -1;

    int maxSum = 0;

    // Sum of first subarray of size k
    for (int i = 0; i < k; i++)
    {
        maxSum += *(arr + i);
    }

    // Check remaining subarrays
    for (int i = 1; i <= size - k; i++)
    {
        int sum = 0;

        for (int j = i; j < i + k; j++)
        {
            sum += *(arr + j);
        }

        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main()
{
    int size, k;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = max_subarray_sum(arr, size, k);

    if (result == -1)
        printf("-1\n");
    else
        printf("Maximum subarray sum: %d\n", result);

    return 0;
}
