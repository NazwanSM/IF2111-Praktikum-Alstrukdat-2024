
#include <stdio.h>
#include <string.h>
#include "listMatkul.h"

// Konstruktor: create tabel kosong
void MakeEmpty(ListMatkul* L) {
    L->Neff = 0;
}

// Mengirimkan banyaknya elemen efektif list
int NbElmt(ListMatkul L) {
    return L.Neff;
}

// Mengirimkan maksimum elemen yang dapat ditampung oleh list
int MaxNbEl(ListMatkul L) {
    return MAX_CAPACITY;
}

// Mengirimkan indeks elemen pertama
IdxType GetFirstIdx(ListMatkul L) {
    return (L.Neff > 0) ? 0 : IDX_UNDEFINED;
}

// Mengirimkan indeks elemen terakhir
IdxType GetLastIdx(ListMatkul L) {
    return (L.Neff > 0) ? L.Neff - 1 : IDX_UNDEFINED;
}

// Mengirimkan elemen list yang ke-i
ElType GetElmt(ListMatkul L, IdxType i) {
    return L.contents[i];
}

// Mengeset nilai elemen list yang ke-i sehingga bernilai v
void SetEl(ListMatkul* L, IdxType i, ElType v) {
    if (i >= 0 && i < MAX_CAPACITY) {
        L->contents[i] = v;
        if (L->Neff <= i) {
            L->Neff = i + 1;
        }
    }
}

// Assignment Lout = Lin
void SetTab(ListMatkul Lin, ListMatkul* Lout) {
    *Lout = Lin;
}

// Mengeset nilai indeks elemen efektif sehingga bernilai N
void SetNeff(ListMatkul* L, IdxType N) {
    if (N <= MAX_CAPACITY) {
        L->Neff = N;
    }
}

// Mengirimkan true jika i adalah indeks yang valid utk ukuran list
boolean IsIdxValid(ListMatkul L, IdxType i) {
    return (i >= 0 && i < MAX_CAPACITY);
}

// Mengirimkan true jika i adalah indeks yang terdefinisi utk list
boolean IsIdxEff(ListMatkul L, IdxType i) {
    return (i >= 0 && i < L.Neff);
}

// Mengirimkan true jika list L kosong
boolean IsEmpty(ListMatkul L) {
    return (L.Neff == 0);
}

// Mengirimkan true jika tabel T penuh
boolean IsFull(ListMatkul L) {
    return (L.Neff == MAX_CAPACITY);
}

// Menuliskan isi list dengan traversal
void PrintIsi(ListMatkul L) {
    if (IsEmpty(L)) {
        printf("List kosong\n");
    } else {
        for (int i = 0; i < L.Neff; i++) {
            printf("%s(%d) - %d: %c\n", L.contents[i].kode, L.contents[i].sks, L.contents[i].semester, L.contents[i].nilai);
        }
    }
}

// Membentuk sebuah ElType dari komponen-komponennya
ElType MakeMatkul(char* kode, int sks, int semester, char nilai) {
    ElType mk;
    mk.kode = kode;
    mk.sks = sks;
    mk.semester = semester;
    mk.nilai = nilai;
    return mk;
}

// Mengembalikan jumlah nilai dalam suatu semester
int SumNilai(ListMatkul L, int semester) {
    int sum = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            switch (L.contents[i].nilai) {
                case 'A': sum += 4 * L.contents[i].sks; break;
                case 'B': sum += 3 * L.contents[i].sks; break;
                case 'C': sum += 2 * L.contents[i].sks; break;
                case 'D': sum += 1 * L.contents[i].sks; break;
                case 'E': sum += 0 * L.contents[i].sks; break;
            }
        }
    }
    return sum;
}

// Menghitung indeks prestasi semester
float HitungIP(ListMatkul L, int semester) {
    float total = 0;
    int totalSKS = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            int point = 0;
            switch (L.contents[i].nilai) {
                case 'A': point = 4; break;
                case 'B': point = 3; break;
                case 'C': point = 2; break;
                case 'D': point = 1; break;
                case 'E': point = 0; break;
            }
            total += point * L.contents[i].sks;
            totalSKS += L.contents[i].sks;
        }
    }
    return totalSKS ? (total / totalSKS) : 0;
}

// Menghitung indeks prestasi kumulatif
float HitungIPK(ListMatkul L) {
    float totalIP = 0;
    int totalSKS = 0;
    for (int sem = 1; sem <= MaxSemester(L); sem++) {
        float ip = HitungIP(L, sem);
        totalIP += ip;
        totalSKS += CountSKS(L, sem);
    }
    return totalSKS ? (totalIP / totalSKS) : 0;
}

// Menghitung jumlah mata kuliah luar yang sudah diambil
int CountMatkulLuar(ListMatkul L, char* kodeJur) {
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (strncmp(L.contents[i].kode, kodeJur, 2) != 0) {
            count++;
        }
    }
    return count;
}

// Menghitung jumlah mata kuliah yang diambil dalam suatu semester
int CountMatkul(ListMatkul L, int semester) {
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            count++;
        }
    }
    return count;
}

// Menghitung jumlah SKS dari mata kuliah yang diambil dalam suatu semester
int CountSKS(ListMatkul L, int semester) {
    int total = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            total += L.contents[i].sks;
        }
    }
    return total;
}

// Mengembalikan jumlah SKS dari mata kuliah yang diambil dari seluruh semester
int CountTotalSKS(ListMatkul L) {
    int total = 0;
    for (int i = 0; i < L.Neff; i++) {
        total += L.contents[i].sks;
    }
    return total;
}

// Mengembalikan semester terakhir yang dijalani dalam list
int MaxSemester(ListMatkul L) {
    int max = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester > max) {
            max = L.contents[i].semester;
        }
    }
    return max;
}

// Menampilkan informasi akademik dari semester terakhir yang dijalani
void DisplaySIX(ListMatkul L) {
    if (IsEmpty(L)) {
        printf("Tidak ada data.\n");
    } else {
        int semester = MaxSemester(L);
        printf("IPK: %.2f\n", HitungIPK(L));
        printf("IP: %.2f\n", HitungIP(L, semester));
        printf("SKS: Sudah Diambil %d SKS\n", CountTotalSKS(L));
        printf("Daftar Kuliah Semester %d:\n", semester);
        for (int i = 0; i < L.Neff; i++) {
            if (L.contents[i].semester == semester) {
                printf("%s(%d) - %d: %c\n", L.contents[i].kode, L.contents[i].sks, L.contents[i].semester, L.contents[i].nilai);
            }
        }
    }
}
