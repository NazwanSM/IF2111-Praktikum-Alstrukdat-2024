#include <stdio.h>
#include "awasketahuan.h"

Stack awasKetahuan(Stack stack){
    Stack temp;
    CreateEmpty(&temp);

    int val;
    while (!IsEmpty(stack)){
        Pop(&stack, &val);
            
        if (val%2 == 0){
            val = val/2;
            Push(&temp, val);
        }
        else{
            Push(&temp, val);
        }
    }

    while (!IsEmpty(temp)){
        int val2;
        Pop(&temp, &val2);
        Push(&stack, val2);
    }

    return stack;
}
/* Mengembalikan sebuah stack berisi integer yang elemen bernilai genapnya sudah dibagi dua */
/* Input berupa stack berisi integer. */
/*
    Contoh input:
        queue : [8, 7, 6, 5, 4, 23 // 8 adalah top
    Contoh output: [4, 7, 3, 5, 2, 3]

    Contoh input:
        queue : [12, 7, 3, 3, 6]
    Contoh output: [6, 7, 3, 3, 3]
*/