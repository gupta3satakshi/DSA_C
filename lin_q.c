#include <stdio.h>
#include <stdlib.h>

// Define structure for queue node
struct Node {
    int data;
    struct Node* next;
};

// Define global variables for front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to initialize queue
void initialize_queue() {
    front = rear = NULL;
}

// Function to check if queue is empty
int is_empty() {
    return front == NULL;
}

// Function to insert element into queue
void insert_element(int item) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("\nMemory allocation failed. Queue is full.");
        return;
    }
    ptr->data = item;
    ptr->next = NULL;
    if (rear == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("\nInserted %d into the queue.", item);
}

// Function to delete element from queue
void delete_element() {
    if (is_empty()) {
        printf("\nQueue is empty. Cannot delete.");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    printf("\nDeleted %d from the queue.", temp->data);
    free(temp);
}

// Function to traverse queue
void traverse_queue() {
    if (is_empty()) {
        printf("\nQueue is empty.");
        return;
    }
    printf("\nQueue elements: ");
    struct Node* current = front;
    while (current != NULL) {
        printf("%d\t ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, item;
    
    initialize_queue();
    
    do {
         printf("\n\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4m MENU FOR LINEAR QUEUE OPERATIONS \033[24m**************");
        printf("\n1. Insert element.");
        printf("\n2. Delete element.");
        printf("\n3. Traverse queue.");
        printf("\n4. Check if queue is empty.");
        printf("\n5. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\033[4m                                                                               . \033[24m");
        switch(choice) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &item);
                insert_element(item);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                traverse_queue();
                break;
            case 4:
                if (is_empty()) {
                    printf("\nQueue is empty.");
                } else {
                    printf("\nQueue is not empty.");
                }
                break;
            case 5:
                printf("\nExiting program.");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while(choice != 5);
    
    return 0;
}
