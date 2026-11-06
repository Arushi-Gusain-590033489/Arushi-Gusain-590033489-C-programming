#include <stdio.h>

int count = 0;

int fibonacci(int n)
{
    count++;

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;

    scanf("%d", &n);

    printf("Fibonacci numbers: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\nNumber of recursive calls: %d\n", count);

    return 0;
}
