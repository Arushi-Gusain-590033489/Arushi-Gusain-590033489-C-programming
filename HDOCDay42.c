#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove all vowels
void removeVowels(char str[])
{
    int i, j = 0;
    char result[100];

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' &&
            str[i] != 'i' && str[i] != 'o' &&
            str[i] != 'u' && str[i] != 'A' &&
            str[i] != 'E' && str[i] != 'I' &&
            str[i] != 'O' && str[i] != 'U')
        {
            result[j] = str[i];
            j++;
        }
    }

    result[j] = '\0';

    printf("String after removing vowels: %s\n", result);
}


// Function to find first repeating lowercase alphabet
void firstRepeating(char str[])
{
    int count[26] = {0};
    int i;

    // Count frequency of lowercase alphabets
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            count[str[i] - 'a']++;
        }
    }

    // Find first character which repeats
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' &&
            count[str[i] - 'a'] > 1)
        {
            printf("First repeating lowercase alphabet: %c\n", str[i]);
            return;
        }
    }

    printf("No repeating lowercase alphabet found.\n");
}


// Function to check anagrams
void checkAnagram(char str1[], char str2[])
{
    int count1[26] = {0};
    int count2[26] = {0};
    int i;

    // Count characters of first string
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (isalpha(str1[i]))
        {
            count1[tolower(str1[i]) - 'a']++;
        }
    }

    // Count characters of second string
    for (i = 0; str2[i] != '\0'; i++)
    {
        if (isalpha(str2[i]))
        {
            count2[tolower(str2[i]) - 'a']++;
        }
    }

    // Compare frequencies
    for (i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            printf("The strings are NOT anagrams.\n");
            return;
        }
    }

    printf("The strings are anagrams.\n");
}


// Main function
int main()
{
    int choice;
    char str[100];
    char str1[100], str2[100];

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Remove all vowels from a string\n");
        printf("2. Find first repeating lowercase alphabet\n");
        printf("3. Check if two strings are anagrams\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';

                removeVowels(str);
                break;

            case 2:
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';

                firstRepeating(str);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                checkAnagram(str1, str2);
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }

    } while (choice != 4);

    return 0;
}
