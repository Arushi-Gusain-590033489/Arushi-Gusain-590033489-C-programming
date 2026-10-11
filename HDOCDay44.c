#include <stdio.h>
#include <string.h>

void reverseWords();
void printInitials();

int main()
{
    int choice;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Reverse each word in a sentence\n");
        printf("2. Print initials of a name\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // removes newline left by scanf

        switch(choice)
        {
            case 1:
                reverseWords();
                break;

            case 2:
                printInitials();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}


/* Function to reverse each word of a sentence */
void reverseWords()
{
    char str[200];
    int i, start, end;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    i = 0;

    while(str[i] != '\0')
    {
        /* Skip spaces */
        if(str[i] == ' ')
        {
            i++;
            continue;
        }

        start = i;

        /* Find end of current word */
        while(str[i] != ' ' && str[i] != '\0')
        {
            i++;
        }

        end = i - 1;

        /* Print the word in reverse */
        while(end >= start)
        {
            printf("%c", str[end]);
            end--;
        }

        if(str[i] == ' ')
            printf(" ");
    }

    printf("\n");
}


/* Function to print initials of a name */
void printInitials()
{
    char name[200];
    int i;

    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    /* First character is an initial */
    if(name[0] != '\0' && name[0] != ' ')
        printf("%c.", name[0]);

    /* Character after every space is another initial */
    for(i = 1; name[i] != '\0'; i++)
    {
        if(name[i - 1] == ' ' && name[i] != ' ')
        {
            printf("%c.", name[i]);
        }
    }

    printf("\n");
}
