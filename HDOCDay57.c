#include <stdio.h>

int max_subarray_sum(int arr[], int n)
{
    int current_sum = arr[0];
    int max_sum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (current_sum + arr[i] > arr[i])
            current_sum = current_sum + arr[i];
        else
            current_sum = arr[i];

        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    return max_sum;
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = max_subarray_sum(arr, n);

    printf("Maximum subarray sum: %d\n", result);

    return 0;
}
