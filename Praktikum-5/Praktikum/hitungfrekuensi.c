#include <stdio.h>
#include "hitungfrekuensi.h"


int hitungfrekuensi(){
    int count = 0;

    START();
    while(!IsEOP()){
        char cc = GetCC();
        if(GetCC() == 'T' || GetCC() == 't'){
            ADV();
            if(GetCC()== 'I' || GetCC() == 'i'){
                ADV();
                if(GetCC() == 'G' || GetCC() == 'g'){
                    ADV();
                    if(GetCC() == 'A' || GetCC() == 'a'){
                        count += 1;
                    }
                }
            }
        }
        ADV();
    }
    return count;
}