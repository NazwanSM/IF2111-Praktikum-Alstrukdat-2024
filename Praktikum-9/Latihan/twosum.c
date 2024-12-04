#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "twosum.h"

int twoSum(List L1, List L2){
    int sum1 = 0;
    int sum2 = 0;
    int multiplier = 1;
    address P = First(L1);
    while (P != Nil){
        sum1 += Info(P) * multiplier;
        multiplier *= 10;
        P = Next(P);
    }
    multiplier = 1;
    P = First(L2);
    while (P != Nil){
        sum2 += Info(P) * multiplier;
        multiplier *= 10;
        P = Next(P);
    }
    return sum1 + sum2;
}

/*
int main(){
    List L1, L2;
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    InsVFirst(&L1, 9);
    InsVFirst(&L1, 9);
    InsVFirst(&L1, 1);
    InsVFirst(&L2, 9);
    printf("%d\n", twoSum(L1, L2));
    return 0;
} */


/* I.S. Masing-masing elemen dari L1 dan L2 merupakan angka dan */
/* L1 maupun L2 tidak kosong */
/* F.S. Menghasilkan angka hasil penjumlahan dua buah list L1 dan L2 */

/* Contoh */
/* L1 = 1 -> 2 -> 3  = 321 */ 
/* L2 = 5 -> 4 = 45 */
/* maka hasilnya adalah */
/* 321 + 45 = 366 */

/* L1 = 1 -> 9 -> 9 */
/* L2 = 9 */
/* maka hasilnya adalah */
/* 991 + 9 = 1000 */
