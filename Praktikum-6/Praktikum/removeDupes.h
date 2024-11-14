#include "queue.h"

Queue removeDupes(Queue queue);
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai duplikat */
/* Input berupa queue yang SUDAH TERURUT. */
/*
    Contoh input:
        queue : [1,1,2,3,4] // 1 adalah head, 4 adalah tail
    Contoh output: [1,2,3,4]

    Contoh input:
        queue : [2,2,2,2,2]
    Contoh output: [2]

*/