#include "queue.h"

int durasiAntre(Queue queue, int k);
/* Mengembalikan sebuah integer yang merupakan durasi total waktu antre */
/* Input berupa queue yang berisi integer dan elemen yang hendak dilacak */
/*
    Contoh input:
        queue = [3,4,2,4,6]
        k = 2
    Contoh output: 8

    Contoh input:
        queue : [3,1,3,6,8]
        k = 1
    Contoh output: 2

    Contoh input:
        Q = [3, 1, 2, 4]
        k = 2
    Contoh output: 6
*/