#include <stdio.h>
#include "mesinkarakter.h"

int main(){
    char c;
    scanf("%c", &c);

    int count = 0;
    START();

    while (!IsEOP()){
        char CC = GetCC();
        if ((CC == 'a' || CC == 'e' || CC == 'u' || CC == 'o' || CC == 'i') && (CC!= c)){
            printf("%c", CC);
            count++;
        }
        ADV();
    }
    if (count == 0){
        printf("0\n");
    }
    else {
        printf(" %d\n", count);
    }
    return 0;
}