#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

typedef struct node node;

// Global pointer to keep track of the start of the linked list
node *start = NULL;

// Function to create a new node
node* getnode() {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

// Function to insert node at the end of the list
void insert_at_end() {
    node *newnode, *temp;
    newnode = getnode();
    
    // If memory allocation failed
    if (newnode == NULL) {
        return;
    }
    
    // If list is empty, make newnode the start
    if (start == NULL) {
        start = newnode;
    } else {
        temp = start;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Link the new node at the end
        temp->next = newnode;
    }
}

// Function to display the list
void display() {
    node *temp = start;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at end\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert_at_end();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
