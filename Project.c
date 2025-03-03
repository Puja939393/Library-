
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 50
#define MAX_AUTHOR 50

struct node {
    int id;
    char author[MAX_AUTHOR];
    char title[MAX_TITLE];
    struct node* next;
} *head;

void addBooks(int id, char title[], char author[]) {
    struct node* newBook = (struct node*)malloc(sizeof(struct node));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = head;
    head = newBook;
    printf("Your book has been added successfully!\n");
}

void displayBooks() {
    struct node* current = head;
    if (current == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("\n--- Book List ---\n");
    while (current != NULL) {
        printf("ID: %d | Title: %s | Author: %s\n", current->id, current->title, current->author);
        current = current->next;
    }
}

void SearchBook(int id) {
    struct node* current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("\nBook Found:\nID: %d | Title: %s | Author: %s\n", current->id, current->title, current->author);
            return;
        }
        current = current->next;
    }
    printf("Book with ID %d not found.\n", id);
}

void deleteBook(int id) {
    struct node *current = head, *prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL)  // If deleting the head node
        head = current->next;
    else
        prev->next = current->next;

    free(current);
    printf("Book deleted successfully.\n");
}

int main() {
    int choice, id;
    char title[MAX_TITLE], author[MAX_AUTHOR];

    while (1) {
        printf("\n--- Library Book Management System ---\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Book Title: ");
                scanf(" %[^\n]", title);
                getchar();
                printf("Enter Author Name: ");
                scanf(" %[^\n]", author);
                addBooks(id, title, author);
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                SearchBook(id);
                break;
            case 4:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
