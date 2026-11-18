#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

struct Student highestMarks(struct Student s[], int n) {
    struct Student highest = s[0];

    for (int i = 1; i < n; i++) {
        if (s[i].marks > highest.marks) {
            highest = s[i];
        }
    }

    return highest;
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    printf("Enter name, roll number and marks:\n");

    for (int i = 0; i < n; i++) {
        scanf("%s %d %f",
              students[i].name,
              &students[i].roll_no,
              &students[i].marks);
    }

    struct Student topper = highestMarks(students, n);

    printf("\nStudent with highest marks:\n");
    printf("%s %d %.2f\n",
           topper.name,
           topper.roll_no,
           topper.marks);

    return 0;
}
