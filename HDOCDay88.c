#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Employee
{
    char name[50];
    int id;
    struct Date joiningDate;
};

int main()
{
    FILE *fp;
    struct Employee emp[100];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of employees.\n");
        return 1;
    }

    /* Input employee details */
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Employee %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %49[^\n]", emp[i].name);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter date of joining (DD MM YYYY): ");
        scanf("%d %d %d",
              &emp[i].joiningDate.day,
              &emp[i].joiningDate.month,
              &emp[i].joiningDate.year);
    }

    /* Open binary file for writing */
    fp = fopen("employee.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    /* Write employee data using fwrite() */
    fwrite(emp, sizeof(struct Employee), n, fp);

    fclose(fp);

    printf("\nEmployee data stored successfully.\n");

    /* Open binary file for reading */
    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    /* Read employee data using fread() */
    printf("\n----- Employee Details -----\n");

    for (i = 0; i < n; i++)
    {
        fread(&emp[i], sizeof(struct Employee), 1, fp);

        printf("\nEmployee %d\n", i + 1);
        printf("Name            : %s\n", emp[i].name);
        printf("ID              : %d\n", emp[i].id);
        printf("Date of Joining : %02d/%02d/%04d\n",
               emp[i].joiningDate.day,
               emp[i].joiningDate.month,
               emp[i].joiningDate.year);
    }

    fclose(fp);

    return 0;
}
