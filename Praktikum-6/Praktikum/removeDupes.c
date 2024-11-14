#include <stdio.h>
#include "removeDupes.h"

Queue removeDupes(Queue queue){
    Queue temp;

    CreateQueue(&temp);

    boolean dupe;

    if(isEmpty(queue)){
        IDX_HEAD(temp) = IDX_UNDEF;
        IDX_TAIL(temp) = IDX_UNDEF;
    }

    while(!isEmpty(queue)){
        ElType val;
        dequeue(&queue, &val);
        if (isEmpty(temp)){
            enqueue(&temp, val);
        }
        else {
            for(int i = IDX_HEAD(temp); i < length(temp); i++){
                if(val == temp.buffer[i]){
                    dupe = 1;
                }
                else{
                    dupe = 0;
                }
            }
            if(!dupe){
                enqueue(&temp, val);
            }
        }
    }
    return temp;
}
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
