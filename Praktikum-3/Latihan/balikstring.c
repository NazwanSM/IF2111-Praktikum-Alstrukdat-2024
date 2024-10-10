#include <stdio.h>
#include "balikstring.h"

// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch){
    int panjang = -1;

    while(*ch != '\0'){
        panjang++;
        ch++;
    }
    return panjang + 1;
}
// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str){
    int panjang = panjangString(str);
    char temp[panjang];
    int j = 0;

    for (int i = panjang - 1; i >= 0; i--){
        temp[j] = str[i];
        j++;
    }
    temp[j] = '\0';

    for (int i = 0; i < panjang; i++){
        str[i] = temp[i];
    }
}

int main() {
    char str[] = "pasya";
    
    printf("Sebelum dibalik: %s\n", str);
    membalikString(str);
    printf("Setelah dibalik: %s\n", str);
    
    return 0;
}