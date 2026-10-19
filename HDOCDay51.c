#include <stdio.h>

void next_greater(int *arr, int size)
{
    int i, j, next;

    for (i = 0; i < size; i++)
    {
        next = -1;

        // Search elements to the right
        for (j = i + 1; j < size; j++)
        {
            if (*(arr + j) > *(arr + i))
            {
                next = *(arr + j);
                break;
            }
        }

        // Print result
        printf("%d", next);

        if (i < size - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

int main()
{
    int size, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Passing array address to function
    next_greater(arr, size);

    return 0;
}
