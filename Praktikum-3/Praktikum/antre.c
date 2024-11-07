#include <stdio.h>

#define MAX_SIZE 100

// Definisi tipe data untuk menyimpan elemen unik
typedef struct {
    int data[MAX_SIZE];
    int size;
} UniqueArray;

// Inisialisasi array
void initArray(UniqueArray *ua) {
    ua->size = 0;
}

// Fungsi untuk menambahkan elemen jika belum ada di dalam array
void addUnique(UniqueArray *ua, int value) {
    int i;
    for (i = 0; i < ua->size; i++) {
        if (ua->data[i] == value) return; // Jika nilai sudah ada, tidak tambahkan
    }
    // Tambahkan nilai baru jika tidak ditemukan di array
    if (ua->size < MAX_SIZE) {
        ua->data[ua->size++] = value;
    }
}

// Fungsi untuk menampilkan elemen unik
void displayUnique(UniqueArray *ua) {
    if (ua->size > 0) {
        for (int i = 0; i < ua->size - 1; i++) {
            printf("%d ", ua->data[i]);
        }
        printf("%d\n", ua->data[ua->size - 1]); // Print elemen terakhir dan newline
    } else {
        printf("\n");
    }
}

int main() {
    UniqueArray ua;
    initArray(&ua);

    int n, value;
    scanf("%d", &n); // Baca jumlah elemen

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        addUnique(&ua, value);
    }

    displayUnique(&ua); // Tampilkan elemen unik

    return 0;
}
