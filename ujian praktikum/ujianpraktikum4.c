#include <stdio.h>

#define MAX 100

// Struktur untuk menyimpan data pengunjung
struct Pengunjung {
    int waktu;  // Waktu pengunjung berada di restoran dalam menit
};

// Struktur untuk menyimpan antrian
struct Queue {
    int front, rear, size;
    struct Pengunjung data[MAX];
};

// Fungsi untuk menginisialisasi antrian
void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Fungsi untuk memeriksa apakah antrian penuh
int isFull(struct Queue *q) {
    return q->size == MAX;
}

// Fungsi untuk memeriksa apakah antrian kosong
int isEmpty(struct Queue *q) {
    return q->size == 0;
}

// Fungsi untuk menambahkan pengunjung ke dalam antrian
void enqueue(struct Queue *q, struct Pengunjung pengunjung) {
    if (isFull(q)) {
        printf("Antrian penuh! Tidak bisa menambahkan pengunjung baru.\n");
        return;
    }
    
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = pengunjung;
    q->size++;
}

// Fungsi untuk mengeluarkan pengunjung dari antrian
struct Pengunjung dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Antrian kosong! Tidak ada pengunjung untuk dikeluarkan.\n");
        struct Pengunjung pengunjungKosong = {0};
        return pengunjungKosong;
    }
    
    struct Pengunjung pengunjung = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    
    return pengunjung;
}

// Fungsi utama
int main() {
    struct Queue q;
    initQueue(&q);
    
    int kapasitasRestoran;
    printf("Masukkan kapasitas maksimal pengunjung di dalam restoran: ");
    scanf("%d", &kapasitasRestoran);
    getchar();  // Membersihkan buffer input

    int n;
    printf("Masukkan jumlah pengunjung: ");
    scanf("%d", &n);
    getchar();  // Membersihkan buffer input

    // Input data pengunjung dari pengguna
    for (int i = 0; i < n; i++) {
        struct Pengunjung pengunjung;

        // Input waktu pengunjung berada di restoran
        printf("\nMasukkan waktu pengunjung %d berada di restoran (menit): ", i + 1);
        scanf("%d", &pengunjung.waktu);
        getchar();  // Membersihkan buffer input

        // Tambahkan pengunjung ke dalam antrian jika kapasitas belum penuh
        if (q.size < kapasitasRestoran) {
            enqueue(&q, pengunjung);
        } else {
            printf("Kapasitas restoran penuh! Pengunjung %d harus menunggu.\n", i + 1);
        }
    }

    // Menampilkan pengunjung yang ada di dalam restoran
    printf("\nPengunjung yang ada di dalam restoran:\n");
    while (!isEmpty(&q)) {
        struct Pengunjung pengunjung = dequeue(&q);
        printf("Waktu pengunjung berada di restoran: %d menit\n", pengunjung.waktu);
    }

    return 0;
}
