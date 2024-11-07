#include <stdio.h>
#include "MinMax.h"

void min(List *L){
    int min = L->A[FirstIdx(*L)];
    int idxMin = FirstIdx(*L);

    for(int i = FirstIdx(*L); i <= LastIdx(*L); i++){
        if (L->A[i] < min){
            min = L->A[i];
            idxMin = i;
        }
    }
    DeleteAt(L, idxMin);
    InsertLast(L, min);
}

void max(List *L){
    int max = L->A[FirstIdx(*L)];
    int idxMax = FirstIdx(*L);

    for(int i = FirstIdx(*L); i <= LastIdx(*L); i++){
        if (L->A[i] > max){
            max = L->A[i];
            idxMax = i;
        }
    }
    DeleteAt(L, idxMax);
    InsertLast(L, max);
}

List MinMax(List L){
    min(L.A);
    max(L.A);
    return L;
}