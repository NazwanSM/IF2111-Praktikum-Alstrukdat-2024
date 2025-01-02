#include <stdio.h>
#include "listsirkuler.h"


int ElemenKeN(List L, int r) {
    address P = First(L);
    int i;
    for (i = 0; i < r; i++) {
        P = Next(P);
    }
    return Info(P);
}

int main () {
    List L;
    int r, el;

    CreateEmpty(&L);
    
    do {
        scanf("%d", &el);
        if (el != 0) {
            InsVLast(&L, el);
        }
    } while (el != 0);

    scanf("%d", &r);
    if (IsEmpty(L)) {
        printf("List Kosong\n");
    } else {
        printf("%d\n", ElemenKeN(L, r));
    }

    return 0;
}