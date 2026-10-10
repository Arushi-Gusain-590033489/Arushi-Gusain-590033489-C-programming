#include <stdio.h>
#include <string.h>

// Function to find the longest word
void longestWord()
{
    char str[200];
    char word[50], longest[50];
    int i = 0, j = 0;
    int maxLength = 0;

    printf("Enter a sentence: ");
    getchar();
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            word[j] = str[i];
            j++;
        }
        else
        {
            word[j] = '\0';

            if (j > maxLength)
            {
                maxLength = j;
                strcpy(longest, word);
            }

            j = 0;
        }

        i++;
    }

    // Check the last word
    if (j > 0)
    {
        word[j] = '\0';

        if (j > maxLength)
        {
            maxLength = j;
            strcpy(longest, word);
        }
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLength);
}


// Function to check rotation
void checkRotation()
{
    char str1[100], str2[100];
    char temp[200];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Lengths must be equal
    if (strlen(str1) != strlen(str2))
    {
        printf("The strings are NOT rotations of each other.\n");
        return;
    }

    // Concatenate first string with itself
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 occurs in temp
    if (strstr(temp, str2) != NULL)
        printf("The strings ARE rotations of each other.\n");
    else
        printf("The strings are NOT rotations of each other.\n");
}


int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Find the longest word in a sentence\n");
        printf("2. Check if one string is a rotation of another\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                longestWord();
                break;

            case 2:
                checkRotation();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
