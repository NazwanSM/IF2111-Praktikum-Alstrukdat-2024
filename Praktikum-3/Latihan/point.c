#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
    POINT P;
    P.X = X;
    P.Y = Y;
    return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
    float X, Y;

    scanf("%f %f", &X, &Y);
    P->X = X;
    P->Y = Y;
    *P = MakePOINT(X, Y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", P.X, P.Y);
}
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    return (P1.X == P2.X) && (P1.Y == P2.Y);
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
    return (P1.X != P2.X) || (P1.Y == P2.Y);
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    return (P.X == 0) && (P.Y == 0);
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P){
    return (P.Y == 0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
    return (P.X == 0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
    if ((P.X > 0) && (P.Y > 0)){
        return 1;
    }
    else if ((P.X < 0) && (P.Y > 0)){
        return 2;
    }
    else if ((P.X < 0) && (P.Y < 0)){
        return 3;
    }
    else {
        return 4;
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    POINT P2;
    P2.X = P.X + deltaX;
    P2.Y = P.Y + deltaY;
    return P2;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
void Geser (POINT *P, float deltaX, float deltaY){
    P->X = P->X + deltaX;
    P->Y = P->Y + deltaY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
float Jarak0 (POINT P){
    return sqrt((P.X * P.X) + (P.Y * P.Y));
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
    return sqrt(((P2.X - P1.X) * (P2.X - P1.X)) + ((P2.Y - P1.Y) * (P2.Y - P1.Y)));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
