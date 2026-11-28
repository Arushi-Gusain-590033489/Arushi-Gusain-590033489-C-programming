#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *input, *output;
    char ch;

    /* Open input.txt for reading */
    input = fopen("input.txt", "r");

    if (input == NULL)
    {
        printf("Error: Unable to open input.txt\n");
        return 1;
    }

    /* Open output.txt for writing */
    output = fopen("output.txt", "w");

    if (output == NULL)
    {
        printf("Error: Unable to create output.txt\n");
        fclose(input);
        return 1;
    }

    /* Read input.txt and convert lowercase letters to uppercase */
    while ((ch = fgetc(input)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = toupper(ch);
        }

        fputc(ch, output);
    }

    fclose(input);
    fclose(output);

    /* Display contents of input.txt */
    input = fopen("input.txt", "r");

    printf("\nContents of input.txt:\n");
    printf("----------------------\n");

    while ((ch = fgetc(input)) != EOF)
    {
        putchar(ch);
    }

    fclose(input);

    /* Display contents of output.txt */
    output = fopen("output.txt", "r");

    printf("\n\nContents of output.txt:\n");
    printf("-----------------------\n");

    while ((ch = fgetc(output)) != EOF)
    {
        putchar(ch);
    }

    fclose(output);

    return 0;
}
