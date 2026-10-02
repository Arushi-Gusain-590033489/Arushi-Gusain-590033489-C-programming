#include <stdio.h>
#include <stdarg.h>

double weightedAverage(int count, ...)
{
    va_list args;
    double value, weight;
    double sum = 0.0, totalWeight = 0.0;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        value = va_arg(args, double);
        weight = va_arg(args, double);

        if (weight < 0)
        {
            printf("Error: Weight cannot be negative.\n");
            va_end(args);
            return -1;
        }

        sum = sum + (value * weight);
        totalWeight = totalWeight + weight;
    }

    va_end(args);

    if (totalWeight == 0)
    {
        printf("Error: Total weight cannot be zero.\n");
        return -1;
    }

    return sum / totalWeight;
}

int main()
{
    double result;

    result = weightedAverage(3, 80.0, 0.3,
                                75.0, 0.2,
                                90.0, 0.5);

    if (result != -1)
    {
        printf("Weighted Average: %.2f\n", result);
    }

    return 0;
}
