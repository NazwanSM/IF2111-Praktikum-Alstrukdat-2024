#include <stdio.h>
#include "arrayGames.h"

/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(TabGames *T){
    T->Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabGames T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl(TabGames T){
    return IdxMax - IdxMin + 1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */

IdxType GetFirstIdx(TabGames T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType GetLastIdx(TabGames T){
    return T.Neff - 1;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */

ElType GetElmt(TabGames T, IdxType i){
    return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab(TabGames T1, TabGames *T2) {
    (*T2) = T1;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */

void SetEl(TabGames *T, IdxType i, ElType v){
    T->TI[i] = v;
    if (i >= (*T).Neff) {
        (*T).Neff = i + 1;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeff(TabGames *T, IdxType N){
    T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabGames T, IdxType i){
    return i >= IdxMin && i <= MaxNbEl(T); 
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff(TabGames T, IdxType i){
    return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabGames T){
    return T.Neff == 0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* *** Test tabel penuh *** */
boolean IsFull(TabGames T){
    return T.Neff == MaxNbEl(T);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabGames T){
    if (IsEmpty(T)){
        printf("Tabel Kosong\n");
    }
    else {
        for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%s | %d | %d\n", T.TI[i].nama, T.TI[i].rating, T.TI[i].harga);
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh print tabel
Test | 8 | 300000
Ini Juga Test | 5 | 12000
Test Lagi | 6 | 50000
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** KONSTRUKTOR GAMES ********** */
ElType MakeGame(char *Nama, int Rating, int Harga){
    ElType G;
    G.nama = Nama;
    G.rating = Rating;
    G.harga = Harga;
    return G;
}
/* Membentuk sebuah Game dari komponen-komponennya */
/* I.S. Nama, Rating, Nilai terdefinisi */
/* F.S. Game G terbentuk dengan Nama, Rating, Harga yang sesuai */

/* ********** OPERATOR STATISTIK GAME ********** */
float RataRataHarga(TabGames T){
    int sum = 0;
    int count = 0;
    float avg;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        sum += T.TI[i].harga;
        count ++;
    }
    avg = (float)sum / count;
    return avg;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan rata-rata harga dari elemen tabel */

float RataRataRating(TabGames T){
    int sum = 0;
    int count = 0;
    float avg;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        sum += T.TI[i].rating;
        count ++;
    }
    avg = (float)sum / count;
    return avg;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan rata-rata rating dari elemen tabel */

int MaxRating(TabGames T){
    int max = T.TI[GetFirstIdx(T)].rating;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].rating > max){
            max = T.TI[i].rating;
        }
    }
    return max;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rating maksimum dari elemen tabel */

int MinRating(TabGames T){
    int min = T.TI[GetFirstIdx(T)].rating;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].rating < min){
            min = T.TI[i].rating;
        }
    }
    return min;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rating minimum dari elemen tabel */

char *MaxHargaNama(TabGames T) {
    int maxHarga = T.TI[GetFirstIdx(T)].harga;
    int idxMax = GetFirstIdx(T);
    
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].harga > maxHarga || (T.TI[i].harga == maxHarga && T.TI[i].rating > T.TI[idxMax].rating)) {
            maxHarga = T.TI[i].harga;
            idxMax = i;
        }
    }
    return T.TI[idxMax].nama;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama game dengan harga tertinggi */
/* Jika ada lebih dari satu game dengan harga tertinggi, maka yang diambil yang memiliki rating lebih tinggi */

char* MinHargaNama(TabGames T) {
    int minHarga = T.TI[GetFirstIdx(T)].harga;
    int idxMin = GetFirstIdx(T);
    
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].harga < minHarga || (T.TI[i].harga == minHarga && T.TI[i].rating > T.TI[idxMin].rating)) {
            minHarga = T.TI[i].harga;
            idxMin = i;
        }
    }
    return T.TI[idxMin].nama;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama game dengan harga tertinggi */
/* Jika ada lebih dari satu game dengan harga terendah, maka yang diambil yang memiliki rating lebih tinggi */

int JumlahGamesRating(TabGames T, int R){
    int count = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].rating == R){
            count++;
        }
    }
    return count;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan jumlah game yang memiliki rating R */
/* Jika tidak ada game yang memiliki rating tersebut, maka menghasilkan 0 */