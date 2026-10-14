#include <stdio.h>

int ceil_index(int *arr, int size, int target)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (*(arr + i) >= target)
        {
            printf("Ceil of %d: %d at index %d\n",
                   target, *(arr + i), i);

            return i;
        }
    }

    printf("-1\n");
    return -1;
}

int main()
{
    int size, target, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d sorted array elements:\n", size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    ceil_index(arr, size, target);

    return 0;
}
