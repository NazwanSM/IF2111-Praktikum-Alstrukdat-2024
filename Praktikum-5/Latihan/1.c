#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main(){
    int len = 0;
    int temp = 0;
    STARTWORD();
    if (!isEndWord()){
        len = CurrentWord.Length;
    }
    while (!isEndWord()){
        temp = CurrentWord.Length;
        ADVWORD();
    }
    len = len + temp;
    printf("%d\n", len);
    return 0;
}