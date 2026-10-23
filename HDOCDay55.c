#include <stdio.h>

void window_maximum(int *arr, int size, int k)
{
    int i, j, max;

    // Check if k is invalid
    if (k <= 0 || k > size)
    {
        printf("-1");
        return;
    }

    // Move the window from left to right
    for (i = 0; i <= size - k; i++)
    {
        max = *(arr + i);

        // Find maximum in current window
        for (j = i + 1; j < i + k; j++)
        {
            if (*(arr + j) > max)
            {
                max = *(arr + j);
            }
        }

        printf("%d", max);

        // Print space between maximum elements
        if (i < size - k)
        {
            printf(" ");
        }
    }
}

int main()
{
    int size, k, i;

    // Read size
    scanf("%d", &size);

    // Variable-length array
    int arr[size];

    // Read array elements
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    // Pass array using its address
    window_maximum(arr, size, k);

    return 0;
}
