#include <stdio.h>

void product_except_self(int *nums, int *answer, int n)
{
    int prefix = 1;
    int suffix = 1;

    // Store prefix products
    for (int i = 0; i < n; i++)
    {
        answer[i] = prefix;
        prefix = prefix * nums[i];
    }

    // Multiply with suffix products
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * suffix;
        suffix = suffix * nums[i];
    }
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    int answer[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Passing arrays using their addresses
    product_except_self(nums, answer, n);

    printf("Output: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d", answer[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("\n");

    return 0;
}
