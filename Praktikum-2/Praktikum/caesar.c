#include <stdio.h>

int main(){
    char str[100];
    char str2[100];
    int i = 0;
    int counter = 0;

    // Membaca input string
    scanf("%s", str);

    // Menghitung jumlah karakter sebelum '.'
    while (str[i] != '.' && str[i] != '\0'){
        i++;
        counter++;
    }

    // Memproses setiap karakter
    for (int i = 0; i < counter; i++){
        // Jika huruf kapital
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str2[i] = ((str[i] - 'A' + counter) % 26) + 'A';
        }
        // Jika huruf kecil
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str2[i] = ((str[i] - 'a' + counter) % 26) + 'a';
        }
        // Selain huruf (tidak diubah)
        else {
            str2[i] = str[i];
        }
    }

    // Menambahkan karakter akhir string
    str2[counter] = '\0';

    // Menampilkan hasil string terenkripsi
    printf("%s\n", str2);

    return 0;
}
