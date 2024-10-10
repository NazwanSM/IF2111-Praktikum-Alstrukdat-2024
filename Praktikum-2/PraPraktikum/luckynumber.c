#include <stdio.h>

int main() {
    int n;
    int fav = 6174;
    int counter = 0;

    // Input
    scanf("%d", &n);
    
    // Validasi input (harus di rentang 1000 ≤ n ≤ 9999)
    if (n < 1000 || n > 9999) {
        printf("-1\n");
        return 0;
    }

    // Proses mencari angka favorit 6174
    while (n != fav) {
        int arr[4];
        int temp = n;

        // Pisahkan digit bilangan ke dalam array
        for (int i = 0; i < 4; i++) {
            arr[i] = temp % 10;
            temp /= 10;
        }

        // Urutkan digit array dalam urutan menurun
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (arr[i] < arr[j]) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }

        // Hitung bilangan terbesar (max) dan terkecil (min)
        int max = 0;
        int min = 0;
        for (int i = 0; i < 4; i++) {
            max = max * 10 + arr[i];
            min = min * 10 + arr[3 - i];
        }

        // Hitung delta
        n = max - min;

        // Jika n == 0, tidak mungkin mencapai 6174
        if (n == 0) {
            counter = -1;
            break;
        }

        // Tambah counter untuk iterasi
        counter++;
    }

    // Output jumlah langkah atau -1 jika tidak bisa mencapai 6174
    printf("%d\n", counter);

    return 0;
}
