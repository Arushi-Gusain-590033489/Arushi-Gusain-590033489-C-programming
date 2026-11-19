#include <stdio.h>
#include <string.h>

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
    struct Employee emp;
    struct Employee *ptr = &emp;

    // Input employee details
    scanf("%s %d %d %d %d",
          emp.name,
          &emp.id,
          &emp.joiningDate.day,
          &emp.joiningDate.month,
          &emp.joiningDate.year);

    // Display before modification using dot operator
    printf("Before modification:\n");
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           emp.name,
           emp.id,
           emp.joiningDate.day,
           emp.joiningDate.month,
           emp.joiningDate.year);

    // Modify details using pointer and arrow operator
    strcpy(ptr->name, "Alan Turing");
    ptr->id = 1001;
    ptr->joiningDate.day = 5;
    ptr->joiningDate.month = 12;
    ptr->joiningDate.year = 2002;

    // Display after modification using arrow operator
    printf("After modification:\n");
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           ptr->name,
           ptr->id,
           ptr->joiningDate.day,
           ptr->joiningDate.month,
           ptr->joiningDate.year);

    return 0;
}
