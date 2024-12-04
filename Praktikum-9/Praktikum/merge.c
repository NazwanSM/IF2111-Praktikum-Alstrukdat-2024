#include <stdio.h>
#include "merge.h"
#include <stdlib.h>

List mergeSortedList(List L1, List L2){
    List L3;
    CreateEmpty(&L3);
    Konkat1(&L1, &L2, &L3);


    List copy;
    CreateEmpty(&copy);
    while (!IsEmpty(L3)){
        address P;
        address max = AdrMax(L3);
        address prmax = First(L3);
        P = First(L3);
        while (P != max){
            prmax = P;
            P = Next(P);
        }
        if (P == prmax){
            DelFirst(&L3, &max);
        } else {
            DelAfter(&L3, &max, prmax);
        }

        InsertFirst(&copy, max);
    }
    First(L3) = First(copy);
}
/*
    Membuat suatu fungsi yang mengambil 2 buah list yang berurutan dan menyatukannya
    menjadi satu buah list yang berurutan. 

    Asumsi List Input : 
    1. List input adalah List linier yang berisi integer
    2. List input mungkin kosong
    3. List input mungkin memiliki lebih dari satu elemen yang sama, misalnya [1,1]
    4. List input pasti berurutan dari kecil ke besar

    CONTOH 1
    input : 
        L1 = [1,1,2,3]
        L2 = [1,2]
    output : [1,1,1,2,2,3]

    CONTOH 2 
    input : 
        L1 = [1,3]
        l2 = [2,4]
    output : [1,2,3,4]

 */