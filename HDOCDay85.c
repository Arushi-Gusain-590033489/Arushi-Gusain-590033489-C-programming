#include <stdio.h>
#include <string.h>

int main()
{
    FILE *source, *destination;
    char sourceFile[100], destinationFile[100];
    char ch;
    char line[500];

    printf("Enter source file name: ");
    scanf("%99s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%99s", destinationFile);

    /* Open source file in read mode */
    source = fopen(sourceFile, "r");

    if (source == NULL)
    {
        printf("Error: Unable to open source file.\n");
        return 1;
    }

    /* Open destination file in write mode */
    destination = fopen(destinationFile, "w");

    if (destination == NULL)
    {
        printf("Error: Unable to open destination file.\n");
        fclose(source);
        return 1;
    }

    /* Copy source file character by character */
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("\nFile copied successfully.\n");

    /* Open destination file in append mode */
    destination = fopen(destinationFile, "a");

    if (destination == NULL)
    {
        printf("Error: Unable to open destination file for appending.\n");
        return 1;
    }

    printf("\nEnter multiple lines of text.\n");
    printf("Type END on a new line to stop:\n");

    getchar();  // Remove newline left by scanf()

    while (1)
    {
        fgets(line, sizeof(line), stdin);

        if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0)
        {
            break;
        }

        fputs(line, destination);
    }

    fclose(destination);

    /* Reopen destination file in read mode */
    destination = fopen(destinationFile, "r");

    if (destination == NULL)
    {
        printf("Error: Unable to open destination file for reading.\n");
        return 1;
    }

    printf("\nComplete contents of destination file:\n");
    printf("--------------------------------------\n");

    while ((ch = fgetc(destination)) != EOF)
    {
        putchar(ch);
    }

    fclose(destination);

    printf("\n--------------------------------------\n");

    return 0;
}
