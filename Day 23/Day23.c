//  Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct Node* newNode;

        if (head1->data <= head2->data) {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } else {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining nodes
    while (head1 != NULL) {
        tail->next = createNode(head1->data);
        tail = tail->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        tail->next = createNode(head2->data);
        tail = tail->next;
        head2 = head2->next;
    }

    return mergedHead;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // List 1: 1 -> 3 -> 5
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    // List 2: 2 -> 4 -> 6
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    struct Node* merged = mergeLists(list1, list2);

    printf("Merged List:\n");
    printList(merged);

    return 0;
}