#include "removeDuplicate.h"
#include "listlinier.h"
#include <stdlib.h>


List removeDuplicate(List l) {
    List newL;
    CreateEmpty(&newL);

    address p;
    infotype X;

    while (!IsEmpty(l)) {
        DelVFirst(&l, &X);

        p = Search(newL, X);

        if (p == Nil) {
            InsVLast(&newL, X);
        }
    }

    return newL;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/