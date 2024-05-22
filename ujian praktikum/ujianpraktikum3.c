#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack penuh\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Konversi karakter angka menjadi integer
int charToInt(char c) {
    return c - '0'; 
}

// Mengonversi setiap karakter menjadi integer
int stringToInt(char *str) {
    int result = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        result = result * 10 + charToInt(str[i]); 
    }
    return result;
}

int main() {
    Stack stack;
    initialize(&stack);

    char input[MAX_SIZE];
    printf("Masukkan string karakter angka: ");
    scanf("%s", input);

    int len = strlen(input);
    
    // Memasukkan setiap karakter dari input ke dalam stack
    for (int i = 0; i < len; i++) {
        push(&stack, input[i]);
    }

    // Mengonversi isi stack menjadi integer
    int result = stringToInt(stack.items);

    printf("Hasil konversi: %d\n", result);

    return 0;
}
