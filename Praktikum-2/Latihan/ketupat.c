#include <stdio.h>

void print_ketupat(int n) {
    int i, j, k;

    // Mencetak bagian atas dari ketupat
    for (i = 1; i <= n; i++) {
        // Cetak spasi
        for (j = n - i; j > 0; j--) {
            printf(" ");
        }
        // Cetak bintang
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Mencetak bagian bawah dari ketupat
    for (i = n; i >= 1; i--) {
        // Cetak spasi
        for (j = n - i; j > 0; j--) {
            printf(" ");
        }
        // Cetak bintang
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int N;
    
    // Meminta pengguna memasukkan panjang sisi miring ketupat
    printf("Masukkan panjang sisi miring ketupat: ");
    scanf("%d", &N);
    
    // Mencetak ketupat
    print_ketupat(N);
    
    return 0;
}
