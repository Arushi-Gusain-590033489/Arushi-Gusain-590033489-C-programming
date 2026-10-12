#include <stdio.h>
#include <string.h>

// Function to change date format
void changeDateFormat()
{
    int day, month, year;

    char *months[] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &day, &month, &year);

    if (month >= 1 && month <= 12)
    {
        printf("Converted date: %02d-%s-%02d\n",
               day, months[month], year % 100);
    }
    else
    {
        printf("Invalid month!\n");
    }
}

// Function to print all substrings
void printSubstrings()
{
    char str[100];
    int i, j, k, len;

    printf("Enter a string: ");
    scanf("%99s", str);

    len = strlen(str);

    printf("All substrings are:\n");

    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            for (k = i; k <= j; k++)
            {
                printf("%c", str[k]);
            }

            if (!(i == len - 1 && j == len - 1))
                printf(",");
        }
    }

    printf("\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Change date format\n");
        printf("2. Print all substrings of a string\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                changeDateFormat();
                break;

            case 2:
                printSubstrings();
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
