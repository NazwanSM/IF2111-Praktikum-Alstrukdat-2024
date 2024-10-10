#include <stdio.h>
#include "garis.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L){
    GARIS L;
    L->PAw = P1;
    L->PAkh = P2;
}
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */


/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
    float x1, y1; scanf("%f %f", &x1, &y1);
    float x2, y2; scanf("%f %f", &x2, &y2);
    POINT P1 = MakePOINT(x1, y1), P2 = MakePOINT(x2, y2);
    while(EQ(P1, P2)) 
    {
        printf("Garis tidak valid\n");
        scanf("%f %f", &x1, &y1);
        scanf("%f %f", &x2, &y2);
        P1 = MakePOINT(x1, y1);
        P2 = MakePOINT(x2, y2);
    }
    MakeGARIS(P1, P2, L);
}
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
    membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
    2 3
    2 3
    Garis tidak valid
    2 3
    3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

void TulisGARIS (GARIS L){
    float x1, x2, y1, y2;
    x1 = X(PAw(L));
    y1 = Y(PAw(L));
    x2 = X(PAkh(L));
    y2 = Y(PAkh(L));

    printf("((%.2f,%.2f),(%.2f,%.2f))", x1, y1, x2, y2);
}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
    tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
/* Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
    float x1, x2, y1, y2;
    x1 = X(PAw(L));
    y1 = Y(PAw(L));
    x2 = X(PAkh(L));
    y2 = Y(PAkh(L));

    return (sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
}
/* Menghitung panjang garis L : berikan rumusnya */
// sqrt [(x2-x1)^2 + (y2-y1)^2] //

float Gradien (GARIS L){
    float x1, x2, y1, y2;
    x1 = X(PAw(L));
    y1 = Y(PAw(L));
    x2 = X(PAkh(L));
    y2 = Y(PAkh(L));

    return (y2-y1)/(x2-x1);
}
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
    return (Gradien(L1)*Gradien(L2) == -1);
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */

boolean IsSejajar (GARIS L1, GARIS L2){
    return (Gradien(L1) == Gradien(L2));    
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */