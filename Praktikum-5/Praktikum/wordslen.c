#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main(void) {
    Word kalimat[100];
    int index = -1;
    STARTWORD();

    while(!isEndWord()) {
        index += 1;
        kalimat[index] = currentWord;
        ADVWORD();
    }
    int awal = kalimat[0].Length;
    int tengah = kalimat[index/2].Length;
    int akhir = kalimat[index].Length;
    printf("%d\n",awal + tengah + akhir);

    return 0;
}