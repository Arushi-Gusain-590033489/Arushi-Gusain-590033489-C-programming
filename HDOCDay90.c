#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char word[100];
    char search[100];
    int count = 0;

    /* Open input.txt in read mode */
    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open input.txt\n");
        return 1;
    }

    /* Take the item to search from the user */
    printf("Enter the item to search: ");
    scanf("%99s", search);

    /* Read each item from the file */
    while (fscanf(fp, "%99s", word) != EOF)
    {
        if (strcmp(word, search) == 0)
        {
            count++;
        }
    }

    /* Display the result */
    if (count > 0)
    {
        printf("\nSearch successful!\n");
        printf("'%s' was found in the file.\n", search);
        printf("Number of occurrences: %d\n", count);
    }
    else
    {
        printf("\nSearch failed!\n");
        printf("'%s' was not found in the file.\n", search);
        printf("Number of occurrences: 0\n");
    }

    fclose(fp);

    return 0;
}
