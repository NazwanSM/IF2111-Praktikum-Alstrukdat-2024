#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>

int main(){
    List L, L2;
    int N = 0;
    CreateEmpty(&L);
    CreateEmpty(&L2);

    scanf("%d", &N);
    while (N >= 0 && N <= 100){
        infotype X = N;
        InsVLast(&L, X);
        InsVFirst(&L2, X);
        scanf("%d", &N);
    }

    if (IsEmpty(L)){
        printf("Daftar nilai kosong\n");
    } 
    else {
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));
        PrintInfo(L);
        printf("\n");
        PrintInfo(L2);
        printf("\n");
    }
    return 0;
}