#include <stdio.h>

void Bubble_sort(int *nums, int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(nums + j) > *(nums + j + 1))
            {
                temp = *(nums + j);
                *(nums + j) = *(nums + j + 1);
                *(nums + j + 1) = temp;
            }
        }
    }
}

void occurrence(int *nums, int size)
{
    int target;
    int first = -1, last = -1;
    int i;

    printf("Enter target: ");
    scanf("%d", &target);

    for (i = 0; i < size; i++)
    {
        if (*(nums + i) == target)
        {
            if (first == -1)
            {
                first = i;
            }

            last = i;
        }
    }

    if (first == -1)
    {
        printf("-1, -1\n");
    }
    else
    {
        printf("First occurrence: %d at index %d\n", target, first);
        printf("Last occurrence: %d at index %d\n", target, last);
    }
}

int main()
{
    int size, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int nums[size];

    printf("Enter %d elements:\n", size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }

    /* Pass array using its address */
    Bubble_sort(nums, size);

    printf("Sorted array: ");

    for (i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    occurrence(nums, size);

    return 0;
}
