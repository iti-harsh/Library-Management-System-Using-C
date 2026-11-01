
#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to store book details
struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
};

// Array of structures
struct Book books[MAX];
int count = 0;

// Function to add a book
void addBook() {
    if (count >= MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].issued = 0;
    count++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks() {
    int i;

    if (count == 0) {
        printf("No books available!\n");
        return;
    }

    printf("\n--- BOOK LIST ---\n");

    for (i = 0; i < count; i++) {
        printf("\nBook ID: %d", books[i].id);
        printf("\nTitle: %s", books[i].title);
        printf("\nAuthor: %s", books[i].author);

        if (books[i].issued == 0)
            printf("\nStatus: Available\n");
        else
            printf("\nStatus: Issued\n");
    }
}

// Function to search for a book
void searchBook() {
    int id, i, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!");
            printf("\nTitle: %s", books[i].title);
            printf("\nAuthor: %s\n", books[i].author);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Book not found!\n");
}

// Function to issue a book
void issueBook() {
    int id, i;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 0) {
                books[i].issued = 1;
                printf("Book issued successfully!\n");
            } else {
                printf("Book is already issued!\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}

// Function to return a book
void returnBook() {
    int id, i;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 1) {
                books[i].issued = 0;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued!\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
