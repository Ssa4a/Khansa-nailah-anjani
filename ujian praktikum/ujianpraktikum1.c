#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_PANJANG_STRING 1000

// Struktur stack untuk menyimpan string
typedef struct {
    char data[MAX_SIZE][MAX_PANJANG_STRING];
    int top;
} Stack;

// Fungsi untuk membuat stack baru dengan menggunakan memori
Stack* createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Fungsi untuk menambahkan elemen ke stack
void push(Stack *stack, const char *str) {
    if (isFull(stack)) {
        printf("Stack penuh! Tidak bisa push elemen baru.\n");
        return;
    }
    stack->top++;
    strncpy(stack->data[stack->top], str, MAX_PANJANG_STRING);
}

// Fungsi untuk menghapus elemen dari stack dan mengembalikan stringnya
char* pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong! Tidak bisa pop elemen.\n");
        return NULL;
    }
    return stack->data[stack->top--];
}

// Fungsi untuk menampilkan elemen dari stack mulai dari atas
void printStack(Stack *stack) {
    printf("Isi stack dari:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s\n", stack->data[i]);
    }
}

int main() {
    Stack *mainStack = createStack();
    Stack *stack1 = createStack();
    Stack *stack2 = createStack();
    Stack *stack3 = createStack();

    int n;
    printf("Masukkan jumlah string yang ingin dimasukkan kedalam stack: ");
    scanf("%d", &n);
    getchar(); // Membersihkan buffer input setelah scanf

    if (n % 3 != 0) {
        printf("Jumlah string harus kelipatan 3.\n");
        return 1;
    }

    // Memasukkan string ke dalam main stack
    printf("Masukkan string:");
    for (int i = 0; i < n; i++) {
        char str[MAX_PANJANG_STRING];
        fgets(str, MAX_PANJANG_STRING, stdin);
        str[strcspn(str, "\n")] = '\0';
        push(mainStack, str);
    }

    // Membagi stack utama ke dalam 3 stack lain secara merata
    while (!isEmpty(mainStack)) {
        if (!isFull(stack1)) {
            push(stack1, pop(mainStack));
        }
        if (!isEmpty(mainStack)) {
            if (!isFull(stack2)) {
                push(stack2, pop(mainStack));
            }
        }
        if (!isEmpty(mainStack)) {
            if (!isFull(stack3)) {
                push(stack3, pop(mainStack));
            }
        }
    }

    // Menampilkan isi dari 3 stack lain dari atas
    printf("\nStack 1:\n");
    printStack(stack1);

    printf("\nStack 2:\n");
    printStack(stack2);

    printf("\nStack 3:\n");
    printStack(stack3);

    free(mainStack);
    free(stack1);
    free(stack2);
    free(stack3);

    return 0;
}
