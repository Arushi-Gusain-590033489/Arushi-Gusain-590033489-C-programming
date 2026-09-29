#include <stdio.h>

void countCharacters()
{
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    while (str[i] != '\0')
    {
        i++;
    }

    printf("Number of characters = %d\n", i);
}

void printCharacters()
{
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("Characters are:\n");

    while (str[i] != '\0')
    {
        printf("%c\n", str[i]);
        i++;
    }
}

void countVowelsConsonants()
{
    char str[100];
    int i = 0, vowels = 0, consonants = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
            str[i] == 'O' || str[i] == 'U')
        {
            vowels++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonants++;
        }

        i++;
    }

    printf("Number of vowels = %d\n", vowels);
    printf("Number of consonants = %d\n", consonants);
}

int main()
{
    int choice;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Count characters in a string\n");
        printf("2. Print each character on a new line\n");
        printf("3. Count vowels and consonants\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                countCharacters();
                break;

            case 2:
                printCharacters();
                break;

            case 3:
                countVowelsConsonants();
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
