#include <stdio.h>

int digitalRoot(int n)
{
    static int count = 0;
    count++;

    printf("Recursive call %d\n", count);

    // Base case
    if (n < 10)
        return n;

    int sum = 0;

    // Calculate sum of digits
    while (n > 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    // Recursive call
    return digitalRoot(sum);
}

int main()
{
    int n, result;

    scanf("%d", &n);

    result = digitalRoot(n);

    printf("Digital root = %d\n", result);

    return 0;
}
