#include <stdio.h>
#include "copyqueue.h"

// Menyalin queue.
void copyQueue(Queue *queueInput, Queue *queueOutput){
    Queue queueTemp;

    CreateQueue(&queueTemp);

    if(isEmpty(*queueInput)){
        IDX_HEAD(*queueOutput) = IDX_UNDEF;
        IDX_TAIL(*queueOutput) = IDX_UNDEF;
    }
    else {
        // Menyalin dari queueInput ke queueTemp dan queueOutput
        while(!isEmpty(*queueInput)) {
            ElType val;
            dequeue(queueInput, &val);
            enqueue(&queueTemp, val);
            enqueue(queueOutput, val);
        }
        
        // Mengembalikan nilai ke queueInput
        while(!isEmpty(queueTemp)) {
            ElType val;
            dequeue(&queueTemp, &val);
            enqueue(queueInput, val);
        }
    }
}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
    Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
    queueInput sementara.
*/