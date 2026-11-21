#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nested structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Structure for Student
struct Student {
    char name[50];
    int id;
    struct Date dob;
};

int main() {
    int n, i;
    int identical = 1;

    struct Student *students1;
    struct Student *students2;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for first array
    students1 = (struct Student *)malloc(n * sizeof(struct Student));

    if (students1 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %49[^\n]", students1[i].name);

        printf("Enter ID: ");
        scanf("%d", &students1[i].id);

        printf("Enter Date of Birth (DD MM YYYY): ");
        scanf("%d %d %d",
              &students1[i].dob.day,
              &students1[i].dob.month,
              &students1[i].dob.year);
    }

    // Dynamically allocate memory for second array
    students2 = (struct Student *)malloc(n * sizeof(struct Student));

    if (students2 == NULL) {
        printf("Memory allocation failed!\n");
        free(students1);
        return 1;
    }

    // Copy records from first array to second array
    for (i = 0; i < n; i++) {
        students2[i] = students1[i];
    }

    // Compare both arrays
    for (i = 0; i < n; i++) {
        if (strcmp(students1[i].name, students2[i].name) != 0 ||
            students1[i].id != students2[i].id ||
            students1[i].dob.day != students2[i].dob.day ||
            students1[i].dob.month != students2[i].dob.month ||
            students1[i].dob.year != students2[i].dob.year) {

            identical = 0;
            break;
        }
    }

    // Print first array
    printf("\n===== RECORDS IN FIRST ARRAY =====\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", students1[i].name);
        printf("ID: %d\n", students1[i].id);
        printf("Date of Birth: %02d/%02d/%04d\n",
               students1[i].dob.day,
               students1[i].dob.month,
               students1[i].dob.year);
    }

    // Print second array
    printf("\n===== RECORDS IN SECOND ARRAY =====\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", students2[i].name);
        printf("ID: %d\n", students2[i].id);
        printf("Date of Birth: %02d/%02d/%04d\n",
               students2[i].dob.day,
               students2[i].dob.month,
               students2[i].dob.year);
    }

    // Display comparison result
    if (identical)
        printf("\nBoth arrays are identical.\n");
    else
        printf("\nBoth arrays are not identical.\n");

    // Release dynamically allocated memory
    free(students1);
    free(students2);

    return 0;
}
