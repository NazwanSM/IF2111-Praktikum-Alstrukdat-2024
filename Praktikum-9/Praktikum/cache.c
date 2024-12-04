#include "listlinier.h"
#include <stdio.h>


int main() {
    int N, Q, i, X;
    address P;
    List cache;

    CreateEmpty(&cache);

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        InsVLast(&cache, i);
    }
    scanf("%d", &Q);


    for (i = 0; i < Q; i++) {
        scanf("%d", &X);

        P = Search(cache, X);

        if (P != Nil) {
            DelP(&cache, X);
            InsVFirst(&cache, X);
            printf("hit ");
            PrintInfo(cache);
            printf("\n");
        } else {
            DelLast(&cache, &P);
            InsVFirst(&cache, X);
            printf("miss ");
            PrintInfo(cache);
            printf("\n");
        }
    }

    return 0;
}