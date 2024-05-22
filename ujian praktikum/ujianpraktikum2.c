#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struktur untuk menyimpan data pasien
struct Pasien {
    char nama[50];
    int prioritas;
};

// Struktur untuk menyimpan antrian
struct Queue {
    int front, rear, size;
    struct Pasien data[MAX];
};

// Fungsi untuk menginisialisasi antrian
void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Fungsi untuk menambahkan pasien ke dalam antrian
void enqueue(struct Queue *q, struct Pasien pasien) {
    if (q->size == MAX) {
        printf("Antrian penuh! Tidak bisa menambahkan pasien baru.\n");
        return;
    }
    
    // Cari posisi yang tepat untuk menambahkan pasien berdasarkan prioritas
    int i = q->rear;
    while (i >= q->front && q->data[i].prioritas <= pasien.prioritas) {
        q->data[i + 1] = q->data[i];
        i--;
    }
    q->data[i + 1] = pasien;
    q->rear++;
    q->size++;
}

// Fungsi untuk mengeluarkan pasien dari antrian
struct Pasien dequeue(struct Queue *q) {
    if (q->size == 0) {
        printf("Antrian kosong! Tidak ada pasien untuk dikeluarkan.\n");
        struct Pasien pasienKosong = {"", -1};
        return pasienKosong;
    }
    struct Pasien pasien = q->data[q->front];
    q->front++;
    q->size--;
    
    // Reset antrian jika kosong
    if (q->size == 0) {
        q->front = 0;
        q->rear = -1;
    }
    return pasien;
}

// Fungsi utama
int main() {
    struct Queue q;
    initQueue(&q);
    
    int n;
    printf("Masukkan jumlah pasien: ");
    scanf("%d", &n);
    getchar();  // Membersihkan buffer input

    // Input data pasien dari pengguna
    for (int i = 0; i < n; i++) {
        struct Pasien pasien;

        // Input nama pasien
        printf("\nMasukkan nama pasien %d: ", i + 1);
        fgets(pasien.nama, sizeof(pasien.nama), stdin);
        pasien.nama[strcspn(pasien.nama, "\n")] = '\0';  // Menghapus newline

        // Input prioritas darurat pasien
        printf("Masukkan prioritas darurat pasien %d (1-tinggi, 2-sedang, 3-rendah): ", i + 1);
        scanf("%d", &pasien.prioritas);
        getchar();  // Membersihkan buffer input

        // Jika prioritas pasien 1, tangani pasien tersebut segera
        if (pasien.prioritas == 1) {
            printf("Pasien dengan prioritas 1 (%s) akan segera ditangani.\n", pasien.nama);
        } else {
            // Masukkan pasien ke dalam antrian jika prioritas bukan 1
            enqueue(&q, pasien);
        }
    }

    // Menampilkan pasien lain yang masih dalam antrian berdasarkan prioritas
    printf("\nPasien lain dalam antrian berdasarkan prioritas:\n");
    while (q.size > 0) {
        struct Pasien pasien = dequeue(&q);
        printf("Nama: %s, Prioritas: %d\n", pasien.nama, pasien.prioritas);
    }

    return 0;
}
