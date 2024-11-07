#include "arrayGames.h"


/* I.S. games terdefinisi dan terisi katalog games yang ada di toko dan Q adalah jumlah aksi yang ditangani */
/* F.S. Menerima Q buah aksi yang masing-masing menjalankan kegiatannya sebagai berikut
        - Aksi 0: Mencetak permainan yang ada di toko saat ini
        - Aksi 1: Mencetak jumlah permainan dengan rating tertinggi
        - Aksi 2: Mencetak nama permainan dengan harga termurah
        - Aksi 3: Mencetak nama-nama permainan dengan rating tertinggi
*/
void UrusToko(TabGames games, int Q);


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

Aksi 1 akan mencetak:
Minecraft | 5 | 50
Terraria | 5 | 50
Apex | 3 | 10
CSGO | 4 | 10
VSCode | 1 | 5

Aksi 2 akan mencetak:
2

Aksi 3 akan mencetak:
VSCode

Aksi 4 akan mencetak:
Minecraft
Terraria

*/
