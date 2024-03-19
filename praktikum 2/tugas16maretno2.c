#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Membuat papan catur dengan nilai awal 0 di setiap index menggunakan loop for 
    for (int s = 0; s < size; s++) {
        for (int t = 0; t < size; t++) {
            *(chessBoard + s*size + t) = 0;
        }
    }
    
    // Menentukan kemungkinan pergerakan kuda
    int kuda[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                       {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    
    // Memperbarui papan catur dengan nilai 1 pada setiap posisi yang dapat dicapai oleh kuda
    for (int k = 0; k < 8; k++) {
        int x = i + kuda[k][0];
        int y = j + kuda[k][1];
        if (x >= 0 && x < size && y >= 0 && y < size) {
            *(chessBoard + x*size + y) = 1;
        }
    }
    
    // Mencetak nilai di setiap baris dan kolom dari array
    for (int s = 0; s < size; s++) {
        for (int t = 0; t < size; t++) {
            printf("%d ", *(chessBoard + s*size + t));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    printf("Halo Selamat datang di program membantu kobo!\n");
    printf("Silahkan masukkan 2 angka : ");
    scanf("%d %d", &i, &j); // Input posisi kuda
    
    int size = 8; // Ukuran papan catur
    int *chessBoard = (int *)malloc(size * size * sizeof(int)); // Alokasi memori untuk papan catur
    
    // Memanggil fungsi untuk mensimulasikan pergerakan kuda
    koboImaginaryChess(i, j, size, chessBoard);
    
    free(chessBoard); // Dealokasi memori untuk papan catur
    
    printf("Program selesai, terimakasih telah membantu kobo!");

    return 0;
}
