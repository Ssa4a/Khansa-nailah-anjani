#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insertNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}

void printList() {
    Node *curr = head;
    if (curr == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("Address: %016lx, Data: %d\n", (unsigned long)curr, curr->data);
        curr = curr->next;
    } while (curr != head);
}

void swapNodes(Node *a, Node *b) {
    // Swapping nodes by adjusting the links
    if (a->next == b) { // a and b are adjacent
        a->next = b->next;
        b->prev = a->prev;
        a->prev->next = b;
        b->next->prev = a;
        b->next = a;
        a->prev = b;
    } else {
        Node *tempNext = a->next;
        Node *tempPrev = a->prev;
        a->next = b->next;
        a->prev = b->prev;
        b->next = tempNext;
        b->prev = tempPrev;
        a->next->prev = a;
        a->prev->next = a;
        b->next->prev = b;
        b->prev->next = b;
    }

    if (head == a) {
        head = b;
    } else if (head == b) {
        head = a;
    }

    if (tail == a) {
        tail = b;
    } else if (tail == b) {
        tail = a;
    }
}

void sortList() {
    if (head == NULL) return;

    int swapped;
    Node *curr;

    do {
        swapped = 0;
        curr = head;

        do {
            Node *nextNode = curr->next;
            if (curr->data > nextNode->data) {
                swapNodes(curr, nextNode);
                swapped = 1;
            } else {
                curr = nextNode;
            }
        } while (curr != tail);
    } while (swapped);
}

int main() {
    int n;
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data);
        insertNode(data);
    }

    printf("\nList sebelum pengurutan:\n");
    printList();

    sortList();

    printf("\nList setelah pengurutan:\n");
    printList();

    return 0;
}
