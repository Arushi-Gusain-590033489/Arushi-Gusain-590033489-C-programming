#include <stdio.h>

void missing_number(int *nums, int size)
{
    int expectedSum, actualSum = 0;
    int missing;

    // Sum of numbers from 0 to size
    expectedSum = size * (size + 1) / 2;

    // Sum of elements present in the array
    for (int i = 0; i < size; i++)
    {
        actualSum += *(nums + i);
    }

    missing = expectedSum - actualSum;

    printf("Missing number: %d\n", missing);
}

int main()
{
    int size;

    scanf("%d", &size);

    // Variable-length array
    int nums[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Passing array address using pointer
    missing_number(nums, size);

    return 0;
}
