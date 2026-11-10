#include <stdio.h>
#include <stdlib.h>

// Create initial attendance matrix
int *createMatrix(int students, int days)
{
    int *matrix = (int *)malloc(students * days * sizeof(int));

    if (matrix == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    return matrix;
}

// Record attendance
void recordAttendance(int *matrix, int start, int students, int days)
{
    for (int i = start; i < students; i++)
    {
        printf("Enter attendance for Student %d (0 or 1):\n", i + 1);

        for (int j = 0; j < days; j++)
        {
            scanf("%d", (matrix + i * days + j));

            // Check invalid input
            while (*(matrix + i * days + j) != 0 &&
                   *(matrix + i * days + j) != 1)
            {
                printf("Invalid! Enter only 0 or 1: ");
                scanf("%d", (matrix + i * days + j));
            }
        }
    }
}

// Add new students using realloc
int *addStudents(int *matrix, int oldStudents,
                 int newStudents, int days)
{
    int totalStudents = oldStudents + newStudents;

    int *temp = (int *)realloc(
        matrix, totalStudents * days * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(matrix);
        exit(1);
    }

    return temp;
}

// Display attendance matrix
void displayAttendance(int *matrix, int students, int days)
{
    printf("\nAttendance Matrix:\n\n");

    printf("Student\t");
    for (int j = 0; j < days; j++)
        printf("Day %d\t", j + 1);

    printf("\n");

    for (int i = 0; i < students; i++)
    {
        printf("%d\t", i + 1);

        for (int j = 0; j < days; j++)
            printf("%d\t", *(matrix + i * days + j));

        printf("\n");
    }
}

// Calculate attendance percentage
void calculatePercentage(int *matrix, int students, int days)
{
    printf("\nAttendance Percentage:\n");

    for (int i = 0; i < students; i++)
    {
        int present = 0;

        for (int j = 0; j < days; j++)
        {
            if (*(matrix + i * days + j) == 1)
                present++;
        }

        float percentage = (present * 100.0) / days;

        printf("Student %d: %.1f%%\n", i + 1, percentage);
    }
}

// Release memory
void releaseMemory(int *matrix)
{
    free(matrix);
}

int main()
{
    int students, days, newStudents;

    printf("Enter initial number of students: ");
    scanf("%d", &students);

    printf("Enter number of working days: ");
    scanf("%d", &days);

    if (students <= 0 || days <= 0)
    {
        printf("Invalid number of students or days.\n");
        return 1;
    }

    // Create initial matrix
    int *attendance = createMatrix(students, days);

    // Record initial attendance
    recordAttendance(attendance, 0, students, days);

    // Display initial matrix
    displayAttendance(attendance, students, days);

    // Add new students
    printf("\nEnter number of additional students: ");
    scanf("%d", &newStudents);

    if (newStudents < 0)
    {
        printf("Invalid number of students.\n");
        releaseMemory(attendance);
        return 1;
    }

    if (newStudents > 0)
    {
        int oldStudents = students;

        attendance = addStudents(attendance,
                                 students,
                                 newStudents,
                                 days);

        students = students + newStudents;

        // Record attendance for newly added students
        recordAttendance(attendance,
                         oldStudents,
                         students,
                         days);
    }

    // Display final attendance matrix
    displayAttendance(attendance, students, days);

    // Calculate attendance percentages
    calculatePercentage(attendance, students, days);

    // Free dynamically allocated memory
    releaseMemory(attendance);

    return 0;
}
