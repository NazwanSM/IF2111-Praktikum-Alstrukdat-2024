/* *** Definisi ABSTRACT DATA TYPE RECTANGLE *** */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "boolean.h"

typedef struct
{
   float width;  /* panjang */
   float height; /* lebar */
} RECTANGLE;

/* *** Notasi Akses: Selektor RECTANGLE *** */
#define Width(R) (R).width
#define Height(R) (R).height

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor memberntuk RECTANGLE *** */
RECTANGLE MakeRectangle(float width, float height);
/* *** Membentuk sebuah RECTANGLE dari komponen-komponennya *** */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void readRectangle(RECTANGLE *R);
/* Membaca nilai panjang dan lebar dari keyboard dan membentuk
   RECTANGLE R berdasarkan dari nilai panjang dan lebar tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk RECTANGLE dengan panjang 1 dan lebar 2 */
/* I.S. Sembarang */
/* F.S. P terdefinisi dengan X menjadi panjang dan Y menjadi lebar */

void printRectangle(RECTANGLE R);
/* Nilai R ditulis ke laayar dengan format "R(PanjangxLebar)"
    misalnya RECTANGLE dengan panjang 1 dan lebar 2 akan ditulis
    sebagai "R(1x2)"
    tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "R(PanjangxLebar)" dengan newline */

/* *** Kelompok operasi relasional terhadap RECTANGLE *** */
boolean isSquare(RECTANGLE R);
/* Mengirimkan true jika width dan Height dari RECTANGLE sama*/
boolean isNotSquare(RECTANGLE R);
/* Mengirimkan true jika width dan Height dari RECTANGLE tidak sama*/

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float area(RECTANGLE R);
/* I.S. R terdefinisi */
/* F.S. Luas R dengan rumus widht * height */

float perimeter(RECTANGLE R);
/* I.S. R terdefinisi */
/* F.S. Keliling R dengan rumus 2 * (width + height) */

void swap(RECTANGLE *R);
/* I.S. R terdefinisi */
/* F.S. R yang panjang dan lebar yang ditukar, sehingga panjang sebesar lebar dan lebar sebesar panjang*/

void add(RECTANGLE *R, float deltaWidth, float deltaHeight);
/* I.S. R terdefinisi */
/* F.S. R yang ditambah panjangnya sebesar deltaWidth dan ditambah lebarnya sebesar deltaHeight */

RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight);
/* Mengirim salinan R yang panjangnya adalah Width(P) + deltaWidth dan ordinatnya adalah Height(P) + deltaHeight */

#endif