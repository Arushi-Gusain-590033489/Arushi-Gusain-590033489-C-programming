#include <stdio.h>
#include <ctype.h>

void countCharacters()
{
    char str[100];
    int i, spaces = 0, digits = 0, special = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            spaces++;
        else if (isdigit(str[i]))
            digits++;
        else if (!isalpha(str[i]))
            special++;
    }

    printf("Number of spaces = %d\n", spaces);
    printf("Number of digits = %d\n", digits);
    printf("Number of special characters = %d\n", special);
}

void countFrequency()
{
    char str[100], ch;
    int i, count = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("Enter character to find: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            count++;
    }

    printf("Frequency of '%c' = %d\n", ch, count);
}

void toggleCase()
{
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        else if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }

    printf("String after toggling case: %s\n", str);
}

int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Count spaces, digits and special characters\n");
        printf("2. Count frequency of a character\n");
        printf("3. Toggle case of each character\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                countCharacters();
                break;

            case 2:
                countFrequency();
                break;

            case 3:
                toggleCase();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
