#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "palindromListLinier.h"

boolean isPalindromeList(List l){
    List Pal; CreateEmpty(&Pal);
    address P = First(l);
    for (int i = 0; i < NbElmt(l); i++){
        InsVLast(&Pal, Info(P));
        P = Next(P);
    }
    // PrintInfo(Pal);
    InversList(&Pal);
    // PrintInfo(Pal);

    P = First(l);
    address Q = First(Pal);
    for (int i = 0; i < NbElmt(l); i++){
        if(Info(P) != Info(Q)){
            return false;
        }
        P = Next(P); Q = Next(Q);
    }
    return true;
}

/*
    Diberikan sebuah list linier l,
    kembalikan true jika list tersebut merupakan palindrome dan false jika tidak.
    Contoh input/output:
    l: [1,2,3,4,5,4,3,2,1]
    expected return: true

    Di atas merupakan palindrome list linier karena jika dibaca dari kiri maupun kanan, tetap sama.

    l: [1,1,2,1]
    expected return: false

    Di atas bukan palindrome list linier karena jika dibaca dari kiri maupun kanan, berbeda. 1,1 dan 1,2.

    P.S. List linier kosong merupakan palindrome.
*/