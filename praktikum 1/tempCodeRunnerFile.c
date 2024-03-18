#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk mendapatkan nilai angka dari kartu
int angkakartu(char card) {
    if (card == 'J') return 11;
    else if (card == 'Q') return 12;
    else if (card == 'K') return 13;
    else if (card == '1') return 10;
    else return (int)(card - '0');
}

// Fungsi untuk menampilkan urutan kartu
void printCards(char *cards, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", cards[i]);
    }
    printf("\n");
}

// Fungsi untuk melakukan pertukaran posisi kartu
void swap(char *kartuA, char *kartuB) {
    char temp = *kartuA;
    *kartuA = *kartuB;
    *kartuB = temp;
}

// Fungsi untuk mengurutkan kartu
int sortCards(char *cards, int length) {
    int swaps = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            // Konversi kartu ke nilai angka untuk membandingkan
            int value1 = angkakartu(cards[j]);
            int value2 = angkakartu(cards[j + 1]);
            if (value1 > value2) {
                swap(&cards[j], &cards[j + 1]);
                swaps++;
                // Menampilkan urutan kartu setiap pertukaran
                printf("Pertukaran %d: ", swaps);
                printCards(cards, length);
            }
        }
    }
    return swaps;
}

int main() {
    int n;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &n);

    char *cards = (char *)malloc(n * sizeof(char));

    printf("Masukkan nilai kartu (1-10, J, Q, K): ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cards[i]);
    }

    int swaps = sortCards(cards, n);

    printf("\nJumlah minimal langkah pertukaran: %d\n", swaps);

    free(cards);
    return 0;
}
