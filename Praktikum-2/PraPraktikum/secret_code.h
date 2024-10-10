/* *** Definisi ABSTRACT fungsi Secret Code*** */

#ifndef SECRET_CODE_H
#define SECRET_CODE_H

/* Fungsi untuk menghitung panjang string sampai karakter '#' */
/* I.S. : str terdefinisi, tidak kosong, tidak lebih dari 20 karakter */
/* F.S. : Mengembalikan panjang string sampai karakter '#' */
int count_length(char str[]);

/* Fungsi untuk mencetak string tanpa angka dan simbol */
/* I.S. : str terdefinisi, tidak kosong, tidak lebih dari 20 karakter */
/* F.S. : Jika str tidak hanya mengandung angka dan simbol, cetak baris kosong */
void print_decrypted(char str[]);

#endif