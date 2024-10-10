#include <stdio.h>
#include "rectangle.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor memberntuk RECTANGLE *** */
RECTANGLE MakeRectangle(float width, float height){
   RECTANGLE R;
   R.width = width;
   R.height = height;
   return R;   
}
/* *** Membentuk sebuah RECTANGLE dari komponen-komponennya *** */
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void readRectangle(RECTANGLE *R){
   float width, height;
   scanf("%f %f", &width, &height);
   R->width = width;
   R->height = height;
}


void printRectangle(RECTANGLE R) {
   printf("R(%.2fx%.2f)\n", R.width, R.height);
}

/* *** Kelompok operasi relasional terhadap RECTANGLE *** */
boolean isSquare(RECTANGLE R){
   return R.width == R.height;
}
/* Mengirimkan true jika width dan Height dari RECTANGLE sama*/
boolean isNotSquare(RECTANGLE R){
   return R.width != R.height;
}
/* Mengirimkan true jika width dan Height dari RECTANGLE tidak sama*/

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float area(RECTANGLE R){
   return R.width * R.height;
}
/* I.S. R terdefinisi */
/* F.S. Luas R dengan rumus widht * height */

float perimeter(RECTANGLE R){
   return 2 * (R.width + R.height);
}
/* I.S. R terdefinisi */
/* F.S. Keliling R dengan rumus 2 * (width + height) */

void swap(RECTANGLE *R){
   float temp;
   temp = R->width;
   R->width = R->height;
   R->height = temp;
}
/* I.S. R terdefinisi */
/* F.S. R yang panjang dan lebar yang ditukar, sehingga panjang sebesar lebar dan lebar sebesar panjang*/

void add(RECTANGLE *R, float deltaWidth, float deltaHeight){
   R->width += deltaWidth;
   R->height += deltaHeight;
}
/* I.S. R terdefinisi */
/* F.S. R yang ditambah panjangnya sebesar deltaWidth dan ditambah lebarnya sebesar deltaHeight */

RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight){
   RECTANGLE newRectangle;
   newRectangle.width = R.width + deltaWidth;
   newRectangle.height = R.height + deltaHeight;
   return newRectangle;
}
/* Mengirim salinan R yang panjangnya adalah Width(P) + deltaWidth dan ordinatnya adalah Height(P) + deltaHeight */