#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertBeginning(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void insertEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
int searchNode(struct Node* head, int key);
int countNodes(struct Node* head);
void traverseList(struct Node* head);

// Function to insert at the beginning
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to delete a specific node
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node
int searchNode(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }

    return -1; // Node not found
}

// Function to count the number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to traverse and print the list
void traverseList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at given position\n");
        printf("3. Insert at end\n");
        printf("4. Delete a specific node\n");
        printf("5. Search for a node\n");
        printf("6. Count the number of nodes\n");
        printf("7. Traverse the list and print\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 4:
                printf("Enter data of the node to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 5:
                printf("Enter data to search for: ");
                scanf("%d", &key);
                position = searchNode(head, key);
                if (position != -1)
                    printf("Node found at position %d\n", position);
                else
                    printf("Node not found\n");
                break;
            case 6:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 7:
                printf("Linked list: ");
                traverseList(head);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
