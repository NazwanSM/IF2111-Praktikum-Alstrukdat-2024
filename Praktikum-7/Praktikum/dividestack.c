#include <stdio.h>
#include "dividestack.h"


void divideStack(Stack *s, Stack *oddS, Stack *evenS){
    int nilai;
    
    Pop(s, &nilai);
    if (!IsEmpty(*s)){
        divideStack(s, oddS, evenS);
    }
    if (nilai%2 != 0){
        Push(oddS, nilai);
    }
    else{
        Push(evenS, nilai);
    }
}
/*
Memisahkan nilai genap dan nilai ganjil dari Stack s.

Awal:
s: 1,2,3,4
evenS:
oddS:

Akhir:
s: 
evenS 2,4
oddS: 1,3

Perhatikan order di dalam stacknya

*/