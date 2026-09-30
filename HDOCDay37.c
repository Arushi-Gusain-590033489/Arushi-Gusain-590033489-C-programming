#include <stdio.h>

void uppercase(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("Uppercase string: %s\n", str);
}

void reverse(char str[])
{
    int i, length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    printf("Reversed string: ");

    for (i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");
}

void palindrome(char str[])
{
    int i, length = 0, flag = 1;

    while (str[length] != '\0')
    {
        length++;
    }

    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

int main()
{
    int choice;
    char str[100];

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Convert lowercase to uppercase\n");
        printf("2. Reverse a string\n");
        printf("3. Check palindrome\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3)
        {
            printf("Enter a string: ");
            scanf("%s", str);
        }

        switch (choice)
        {
            case 1:
                uppercase(str);
                break;

            case 2:
                reverse(str);
                break;

            case 3:
                palindrome(str);
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
