#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

// Function to print all members of a student structure
void printStudent(struct Student s) {
    printf("%s %d %.2f\n", s.name, s.roll_no, s.marks);
}

int main() {
    int n, i, maxIndex = 0;
    char choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll number: ");
        scanf("%d", &students[i].roll_no);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("a. Find student with highest marks\n");
        printf("b. Print all students\n");
        printf("c. Exit\n");

        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
                maxIndex = 0;

                for (i = 1; i < n; i++) {
                    if (students[i].marks > students[maxIndex].marks) {
                        maxIndex = i;
                    }
                }

                printf("\nStudent with highest marks:\n");
                printStudent(students[maxIndex]);
                break;

            case 'b':
            case 'B':
                printf("\nStudent Details:\n");

                for (i = 0; i < n; i++) {
                    printStudent(students[i]);
                }
                break;

            case 'c':
            case 'C':
                printf("Program exits\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
