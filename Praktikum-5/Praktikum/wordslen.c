#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

int hitungPanjangKata() {
    int length = 0;
    while (currentChar != BLANK && !EOP) {
        if ((currentChar >= 'A' && currentChar <= 'Z') || 
            (currentChar >= 'a' && currentChar <= 'z') ||
            (currentChar >= '0' && currentChar <= '9')) {
            length++;
        }
        ADV();
    }
    return length;
}

int main() {
    int totalKata = 0;
    int panjangPertama = 0, panjangTengah = 0, panjangTerakhir = 0;
    int posisiTengah;
    
    START();

    // Cek apakah string kosong
    if (EOP) {
        printf("0\n");
        return 0;
    }

    // Lewati spasi awal
    while (currentChar == BLANK && !EOP) {
        ADV();
    }

    // Cek lagi apakah sudah EOP setelah melewati spasi
    if (EOP) {
        printf("0\n");
        return 0;
    }
    
    // Hitung total kata dan panjang kata pertama
    totalKata++;
    panjangPertama = hitungPanjangKata();
    panjangTerakhir = panjangPertama; // Inisialisasi panjangTerakhir
    
    // Hitung kata-kata lainnya
    while (!EOP) {
        if (currentChar == BLANK) {
            do {
                ADV();
            } while (currentChar == BLANK && !EOP);
            
            if (!EOP) {
                totalKata++;
                int panjangKata = hitungPanjangKata();
                panjangTerakhir = panjangKata;
            }
        } else {
            ADV();
        }
    }
    
    // Hitung kata tengah
    if (totalKata > 1) {
        posisiTengah = totalKata / 2 + (totalKata % 2 == 0 ? 0 : 1);
        
        START();
        int kataKe = 0;
        
        while (kataKe < posisiTengah && !EOP) {
            while (currentChar == BLANK && !EOP) {
                ADV();
            }
            if (!EOP) {
                kataKe++;
                if (kataKe == posisiTengah) {
                    panjangTengah = hitungPanjangKata();
                } else {
                    while (currentChar != BLANK && !EOP) {
                        ADV();
                    }
                }
            }
        }
    } else {
        // Jika hanya ada satu kata atau kurang
        panjangTengah = panjangPertama;
    }
    
    // Jumlahkan dan cetak hasil
    int hasil = panjangPertama + panjangTengah + panjangTerakhir;
    printf("%d\n", hasil);
    
    return 0;
}
