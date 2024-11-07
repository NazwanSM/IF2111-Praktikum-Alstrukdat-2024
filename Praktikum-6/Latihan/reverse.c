#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2)
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
{
    HEAD(*q2) = HEAD(*q1);
    TAIL(*q2) = TAIL(*q1);

    int i, j = 0;

    for (i = TAIL(*q1); i >= HEAD(*q1); i--)
    {
        (*q2).Tab[j] = (*q1).Tab[i];
        j += 1;
    }
}

// int main()
// {
//     Queue que;
//     Queue que2;
//     que = CreateQueue(5);

//     Push(&que, 5);
//     Push(&que, 6);
//     Push(&que, 9);
    
//     for (int i = que.HEAD; i <= que.TAIL; i++)
//     {
//         printf("%d\n", que.Tab[i]);
//     }

//     transferReverse(&que, &que2);
    
//     printf("-------------");
//     for (int i = que2.HEAD; i <= que2.TAIL; i++)
//     {
//         printf("%d", que2.Tab[i]);
//     }
// }