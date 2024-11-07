#include <stdio.h>
#include "mesinkarakterv2.h"
#include "mesinkata.h"

void geser(char *word, int n, int length)
{
    for(int i = 0; i < length; i++)
    { 
        if (word[i] >= 'A' && word[i] <= 'Z') {  
            word[i] = 'A' + ((word[i] - 'A' + n) % 26);
        }
    }
}

int main(){
    STARTWORD();
    int n = currentWord.Length;

    do
    {
        int length = currentWord.Length;
        geser(currentWord.TabWord, n, length);
        for(int i = 0; i < currentWord.Length; i++){
            printf("%c", currentWord.TabWord[i]);
        }

        if (EOP){
            if (currentWord.TabWord[currentWord.Length - 1] != '.') {
                printf(".");  // Tambahkan titik jika belum ada
            }
            printf("\n");
            break;
        }
        else{
            printf(" ");
        }
        
        ADVWORD();
    } while (true);
    
    return 0;
}
