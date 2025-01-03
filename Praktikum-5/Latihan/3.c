#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>

void flip(char *word, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        char temp = word[i];
        word[i] = word[n-i-1];
        word[n-i-1] = temp;
    }
}

int main()
{
    char qwerty[] = "qwerty";
    STARTWORD();
    do
    {
        for(int i = 0; i < CurrentWord.Length; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(CurrentWord.TabWord[i] == qwerty[j])
                {
                    flip(CurrentWord.TabWord, i);
                    break;
                }
            }
        }
        
        for(int i = 0; i < CurrentWord.Length; i++)
        {
            printf("%c", CurrentWord.TabWord[i]);
        }

        if (EOP){
            printf(".\n");
            break;
        }
        else{
            printf(" ");
        }
        
        ADVWORD();
    } while (true);
}