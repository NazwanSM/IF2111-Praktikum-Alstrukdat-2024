#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    List L, temp;
    CreateEmpty(&L);
    CreateEmpty(&temp);

    int N = 0;
    scanf("%d", &N);
    while (N!=-99){
        if (Search(L, N) == Nil){
            InsVLast(&L, N);
        }
        scanf("%d", &N);
    }

    List remaining; CreateEmpty(&remaining);
    address P = First(L);
    for (int i = 0; i < NbElmt(L); i++){
        InsVLast(&remaining, Info(P));
        P = Next(P);
    }

    int tebak; scanf("%d", &tebak);
    boolean found = Search(L, tebak) != Nil;
    while (found && NbElmt(remaining) != 0){
        if (Search(remaining, tebak) != Nil){
            DelP(&remaining, tebak);
        }
        
        if (NbElmt(remaining)!=0){
            scanf("%d", &tebak);
            found = Search(L, tebak) != Nil;
        }
    }

    if (!found){
        printf("Poser! %d tidak ada di dalam album\n", tebak);
    }
    else{
        printf("Berhasil menebak %d lagu\n", NbElmt(L));
    }
    return 0;
}