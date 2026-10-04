#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define WORD 100

void readParagraph(char paragraph[], size_t size);
void findLongestAndShortestWords(const char paragraph[],
                                 char longestWord[],
                                 char shortestWord[]);
void removeRepeatedSpaces(const char paragraph[],
                          char modifiedParagraph[]);
void convertToTitleCase(const char paragraph[],
                        char titleCaseParagraph[]);
void findWordFrequencies(const char paragraph[]);

int main()
{
    char paragraph1[SIZE], paragraph2[SIZE];
    char longest[WORD], shortest[WORD];
    char modified[SIZE], titleCase[SIZE];

    int choice;

    printf("Enter Paragraph 1:\n");
    readParagraph(paragraph1, SIZE);

    printf("\nEnter Paragraph 2:\n");
    readParagraph(paragraph2, SIZE);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Find longest and shortest words\n");
        printf("2. Remove repeated spaces\n");
        printf("3. Convert paragraphs to title case\n");
        printf("4. Find word frequencies\n");
        printf("5. Display original paragraphs\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                findLongestAndShortestWords(paragraph1, longest, shortest);
                printf("\nParagraph 1:\n");
                printf("Longest word  : %s\n", longest);
                printf("Shortest word : %s\n", shortest);

                findLongestAndShortestWords(paragraph2, longest, shortest);
                printf("\nParagraph 2:\n");
                printf("Longest word  : %s\n", longest);
                printf("Shortest word : %s\n", shortest);
                break;

            case 2:
                removeRepeatedSpaces(paragraph1, modified);
                printf("\nModified Paragraph 1:\n%s\n", modified);

                removeRepeatedSpaces(paragraph2, modified);
                printf("\nModified Paragraph 2:\n%s\n", modified);
                break;

            case 3:
                convertToTitleCase(paragraph1, titleCase);
                printf("\nTitle Case Paragraph 1:\n%s\n", titleCase);

                convertToTitleCase(paragraph2, titleCase);
                printf("\nTitle Case Paragraph 2:\n%s\n", titleCase);
                break;

            case 4:
                printf("\nWord Frequencies in Paragraph 1:\n");
                findWordFrequencies(paragraph1);

                printf("\nWord Frequencies in Paragraph 2:\n");
                findWordFrequencies(paragraph2);
                break;

            case 5:
                printf("\nParagraph 1:\n%s\n", paragraph1);
                printf("\nParagraph 2:\n%s\n", paragraph2);
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}


/* Function to read a paragraph */
void readParagraph(char paragraph[], size_t size)
{
    fgets(paragraph, size, stdin);

    /* Remove newline added by fgets */
    paragraph[strcspn(paragraph, "\n")] = '\0';
}


/* Find longest and shortest words */
void findLongestAndShortestWords(const char paragraph[],
                                 char longestWord[],
                                 char shortestWord[])
{
    char temp[SIZE];
    char *word;

    strcpy(temp, paragraph);

    word = strtok(temp, " ,.!?;:");

    if (word == NULL)
    {
        strcpy(longestWord, "");
        strcpy(shortestWord, "");
        return;
    }

    strcpy(longestWord, word);
    strcpy(shortestWord, word);

    while (word != NULL)
    {
        if (strlen(word) > strlen(longestWord))
        {
            strcpy(longestWord, word);
        }

        if (strlen(word) < strlen(shortestWord))
        {
            strcpy(shortestWord, word);
        }

        word = strtok(NULL, " ,.!?;:");
    }
}


/* Remove repeated consecutive spaces */
void removeRepeatedSpaces(const char paragraph[],
                          char modifiedParagraph[])
{
    int i, j = 0;
    int previousSpace = 0;

    for (i = 0; paragraph[i] != '\0'; i++)
    {
        if (isspace((unsigned char)paragraph[i]))
        {
            if (!previousSpace)
            {
                modifiedParagraph[j++] = ' ';
                previousSpace = 1;
            }
        }
        else
        {
            modifiedParagraph[j++] = paragraph[i];
            previousSpace = 0;
        }
    }

    modifiedParagraph[j] = '\0';
}


/* Convert paragraph to title case */
void convertToTitleCase(const char paragraph[],
                        char titleCaseParagraph[])
{
    int i;
    int newWord = 1;

    for (i = 0; paragraph[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)paragraph[i]))
        {
            if (newWord)
            {
                titleCaseParagraph[i] =
                    toupper((unsigned char)paragraph[i]);

                newWord = 0;
            }
            else
            {
                titleCaseParagraph[i] =
                    tolower((unsigned char)paragraph[i]);
            }
        }
        else
        {
            titleCaseParagraph[i] = paragraph[i];

            if (isspace((unsigned char)paragraph[i]))
            {
                newWord = 1;
            }
        }
    }

    titleCaseParagraph[i] = '\0';
}


/* Find frequency of each distinct word */
void findWordFrequencies(const char paragraph[])
{
    char temp[SIZE];
    char words[100][WORD];
    int frequency[100];

    int count = 0;
    int i, j;
    int found;

    char *word;

    strcpy(temp, paragraph);

    /* Convert paragraph to lowercase */
    for (i = 0; temp[i] != '\0'; i++)
    {
        temp[i] = tolower((unsigned char)temp[i]);
    }

    word = strtok(temp, " ,.!?;:");

    while (word != NULL)
    {
        found = 0;

        for (i = 0; i < count; i++)
        {
            if (strcmp(words[i], word) == 0)
            {
                frequency[i]++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            strcpy(words[count], word);
            frequency[count] = 1;
            count++;
        }

        word = strtok(NULL, " ,.!?;:");
    }

    for (j = 0; j < count; j++)
    {
        printf("%s : %d\n", words[j], frequency[j]);
    }
}
