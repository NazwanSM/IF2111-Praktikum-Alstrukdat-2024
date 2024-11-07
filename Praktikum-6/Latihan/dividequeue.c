#include <stdio.h>
#include "dividequeue.h"


// Membagi queue.
void divideQueue(Queue *queue, Queue *oddQueue, Queue *evenQueue){
    Queue queueTemp;
    
    CreateQueue(&queueTemp);
    
    if(isEmpty(*queue)){
        IDX_HEAD(*oddQueue) = IDX_UNDEF;
        IDX_TAIL(*oddQueue) = IDX_UNDEF;
        IDX_HEAD(*evenQueue) = IDX_UNDEF;
        IDX_TAIL(*evenQueue) = IDX_UNDEF;
    }
    
    else {
        while(!isEmpty(*queue)){
            ElType val;
            dequeue(queue, &val);
            enqueue(&queueTemp, val);
            if(val % 2 == 0){
                enqueue(evenQueue, val);
            }
            else {
                enqueue(oddQueue,val);
            }
        }
        while(!isEmpty(queueTemp)){
            ElType val;
            dequeue(&queueTemp, &val);
            enqueue(queue, val);
        }
    }
}
/* Proses: Membagi isi dari queue ke oddQueue untuk elemen ganjil dan evenQueue untuk elemen genap */
/* I.S. queue mungkin kosong, tabel penampung elemen queue TIDAK penuh */
/* F.S. oddQueue memiliki isi queue elemen ganjil, evenQueue memiliki isi queue elemen genap */
/*
    Contoh input:
    queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    oddQueue: queue kosong
    evenQueue: queue kosong

    Contoh output:
    queue:  [2,3,4,5,6]
    oddQueue: [3,5]
    evenQueue: [2,4,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
    Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queue, oddQueue, dan evenQueue untuk tempat penyimpanan
    queue sementara.
*/