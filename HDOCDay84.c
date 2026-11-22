#include <stdio.h>

int main()
{
    char name[100];
    int age;
    FILE *fp;
    char line[200];

    // Taking user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    // Opening file in write mode
    fp = fopen("info.txt", "w");

    // Checking file-opening error
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Writing data to file using fprintf()
    fprintf(fp, "Name: %s", name);
    fprintf(fp, "Age: %d\n", age);

    printf("Data written successfully to info.txt\n");

    // Closing the file
    fclose(fp);

    // Reopening file in read mode
    fp = fopen("info.txt", "r");

    // Checking file-opening error
    if (fp == NULL)
    {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nContents of info.txt:\n");

    // Reading file line by line until EOF
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    // Closing the file
    fclose(fp);

    return 0;
}
