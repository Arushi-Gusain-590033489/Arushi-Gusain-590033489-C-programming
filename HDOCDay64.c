#include <stdio.h>

void duplicate_element(int *nums, int n)
{
    int xorArray = 0;
    int xorRange = 0;

    // XOR all elements of the array
    for (int i = 0; i < n; i++)
    {
        xorArray ^= *(nums + i);
    }

    // XOR numbers from 1 to n-1
    for (int i = 1; i < n; i++)
    {
        xorRange ^= i;
    }

    int duplicate = xorArray ^ xorRange;

    printf("Repeated element: %d\n", duplicate);
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    duplicate_element(nums, n);

    return 0;
}
