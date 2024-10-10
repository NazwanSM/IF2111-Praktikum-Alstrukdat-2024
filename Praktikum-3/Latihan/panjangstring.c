#include <stdio.h>
#include "panjangstring.h"

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string

int panjangString(char* str){
    int i=-1;
    char* cc=str;

    while (*cc != '\0'){
        cc++;
        i++;
    }
    return i+1;
}
