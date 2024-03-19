#include <stdio.h>

// Fungsi untuk mendapatkan nilai numerik kartu
int get_value(char c) { //pakai c karena c dari kata card
    if (c == 'J')
        return 11;
    else if (c == 'Q')
        return 12;
    else if (c == 'K')
        return 13;
    else if (c == '1')
        return 10;
    else
        return c - '0';
}

// Fungsi untuk melakukan pertukaran kartu dan akan mengembalikan jumlah pertukaran
int swapping(int n, char *cards) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (get_value(cards[j]) < get_value(cards[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char temp = cards[i];
            cards[i] = cards[min_idx];
            cards[min_idx] = temp;
            swaps++;
        }
    }
    return swaps;
}

// Fungsi untuk mencetak urutan kartu yang telah di proses diatas
void print_cards(int n, char *cards) {
    for (int i = 0; i < n; i++) {
        printf("%c ", cards[i]);
    }
    printf("\n");
}

//fungsi utama program 
int main() {
    int pilih;
    do {
        printf("\nSelamat datang pada program calculate exchange cards\n");
        printf("=====================================================\n");
        printf("Menu:\n");
        printf("1. Hitung jumlah minimal langkah pertukaran\n");
        printf("2. Tampilkan proses urutan kartu setiap terjadi pertukaran (bonus)\n");
        printf("3. Keluar program\n");

        printf("Pilih menu (dengan angka) : ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: {
                int jumlahkartu;
                printf("Masukkan jumlah kartu : ");
                scanf("%d", &jumlahkartu);

                char cards[jumlahkartu];
                printf("Masukkan nilai kartu dengan spasi: ");
                for (int i = 0; i < jumlahkartu; i++) {
                    scanf(" %c", &cards[i]);
                }

                int swaps = swapping(jumlahkartu, cards);
                printf("Jumlah minimal langkah pertukaran: %d\n", swaps);
                printf("\n");
                break;
            }
            case 2: {
                int jumlahkartu;
                printf("\nMasukkan jumlah kartu: ");
                scanf("%d", &jumlahkartu);

                char cards[jumlahkartu];
                printf("Masukkan nilai kartu dengan spasi: ");
                for (int i = 0; i < jumlahkartu; i++) {
                    scanf(" %c", &cards[i]);
                }

                int swaps = swapping(jumlahkartu, cards);
                printf("Urutan kartu setiap terjadi pertukaran (minimal 5 kali):\n");
                for (int i = 0; i < 5 && swaps > 0; i++) {
                    print_cards(jumlahkartu, cards);
                    swapping(jumlahkartu, cards);
                }
                break;
            }
            case 3:
                printf("Keluar dari program,sampai berjumpa lagi!\n");
                printf("==========================================\n");

                break;
            default:
                printf("Pilihan tidak valid\n");
                printf("====================");
        }
    } while (pilih != 3);

    return 0;
}
