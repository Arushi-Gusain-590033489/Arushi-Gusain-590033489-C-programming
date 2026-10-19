#include <stdio.h>

void previous_greater(int *arr, int size)
{
    int i, j, prev;

    for (i = 0; i < size; i++)
    {
        prev = -1;

        // Search elements to the left
        for (j = i - 1; j >= 0; j--)
        {
            if (*(arr + j) > *(arr + i))
            {
                prev = *(arr + j);
                break;
            }
        }

        printf("%d", prev);

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

    // Passing the address of array
    previous_greater(arr, size);

    return 0;
}
