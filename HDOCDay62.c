#include <stdio.h>

void merge_sorted_arrays(int *arr1, int n1, int *arr2, int n2, int *merged)
{
    int i = 0, j = 0, k = 0;

    // Compare elements of both arrays
    while (i < n1 && j < n2)
    {
        if (*(arr1 + i) <= *(arr2 + j))
        {
            *(merged + k) = *(arr1 + i);
            i++;
        }
        else
        {
            *(merged + k) = *(arr2 + j);
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1
    while (i < n1)
    {
        *(merged + k) = *(arr1 + i);
        i++;
        k++;
    }

    // Copy remaining elements of arr2
    while (j < n2)
    {
        *(merged + k) = *(arr2 + j);
        j++;
        k++;
    }
}

int main()
{
    int n1, n2;

    scanf("%d", &n1);
    int arr1[n1];

    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &n2);
    int arr2[n2];

    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    int merged[n1 + n2];

    merge_sorted_arrays(arr1, n1, arr2, n2, merged);

    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d", merged[i]);

        if (i < n1 + n2 - 1)
            printf(" ");
    }

    return 0;
}
