#include <stdio.h>
#include <string.h>

enum BookType {
    FICTION,
    NON_FICTION,
    REFERENCE
};

struct Book {
    char title[100];
    char author[100];
    enum BookType type;
};

int main() {
    struct Book book;
    int choice;

    printf("Enter book title: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0';

    printf("Enter author name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0';

    printf("Enter book type (0-Fiction, 1-Non-Fiction, 2-Reference): ");
    scanf("%d", &choice);

    book.type = choice;

    printf("\nBook Details\n");
    printf("--------------------\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);

    printf("Book Type: ");

    switch (book.type) {
        case FICTION:
            printf("Fiction\n");
            break;

        case NON_FICTION:
            printf("Non-Fiction\n");
            break;

        case REFERENCE:
            printf("Reference\n");
            break;

        default:
            printf("Invalid Book Type\n");
    }

    return 0;
}
