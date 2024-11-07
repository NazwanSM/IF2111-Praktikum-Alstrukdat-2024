#include <stdio.h>
#include "gamestore.h"

void Aksi0 (TabGames games){
    TulisIsi(games);
}

void Aksi1 (TabGames games){
    int max = MaxRating(games);
    int count = 0;

    for (int i = GetFirstIdx(games); i <= GetLastIdx(games); i++){
        if (games.TI[i].rating == max){
            count++;
        }
    }
    printf("%d\n", count);
}

void Aksi2 (TabGames games){
    char *nama = MinHargaNama(games);

    printf("%s\n", nama);
}

void Aksi3 (TabGames games){
    int max = MaxRating(games);
    for (int i = GetFirstIdx(games); i <= GetLastIdx(games); i++){
        if (games.TI[i].rating == max){
            printf("%s\n", games.TI[i].nama);
        }
    }
}

/* I.S. games terdefinisi dan terisi katalog games yang ada di toko dan Q adalah jumlah aksi yang ditangani */
/* F.S. Menerima Q buah aksi yang masing-masing menjalankan kegiatannya sebagai berikut
        - Aksi 0: Mencetak permainan yang ada di toko saat ini
        - Aksi 1: Mencetak jumlah permainan dengan rating tertinggi
        - Aksi 2: Mencetak nama permainan dengan harga termurah
        - Aksi 3: Mencetak nama-nama permainan dengan rating tertinggi
*/
void UrusToko(TabGames games, int Q){
    int aksi[Q];
    
    for (int i = 0; i < Q; i++){
        scanf("%d", &aksi[i]);
    }

    for (int i = 0; i < Q; i++){
        if(aksi[i] == 0){
            Aksi0(games);
        } else if (aksi[i] == 1){
            Aksi1(games);
        } else if (aksi[i] == 2){
            Aksi2(games);
        } else if (aksi[i] == 3){
            Aksi3(games);
        }
    }

}


/*
CONTOH JALAN:
I.S. 
Q bernilai: 4 dan TabGames games berisi:
Minecraft | 5 | 50
Terraria | 5 | 50
Apex | 3 | 10
CSGO | 4 | 10
VSCode | 1 | 5

F.S. Diberikan aksi 0, 1, 2, dan 3 maka output yang keluar adalah
Minecraft | 5 | 50
Terraria | 5 | 50
Apex | 3 | 10
CSGO | 4 | 10
VSCode | 1 | 5
2
VSCode
Minecraft
Terraria
*/