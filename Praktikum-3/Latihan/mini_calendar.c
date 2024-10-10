#include <stdio.h>
#include <stdbool.h>

// Prototipe fungsi
bool is_leap_year(int year);
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add);
const char* get_month_name(int month);
const char* get_day_of_week(int day, int month, int year);
int count_sundays_in_year(int year);

// Hari dalam seminggu
const char* days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Jumlah hari dalam tiap bulan
int days_in_month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31};

// Cek apakah tahun kabisat
bool is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Menambah hari pada tanggal
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    int days_left_in_month;
    while (days_left_to_add > 0) {
        days_left_in_month = days_in_month[*mm] - *dd;
        if (*mm == 2 && is_leap_year(*yy)) {
            days_left_in_month++;
        }
        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= days_left_in_month + 1;
            *dd = 1;
            if (*mm == 12) {
                *mm = 1;
                *yy = *yy + 1;
            } else {
                *mm = *mm + 1;
            }
        } else {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

// Mengembalikan nama bulan dari angka
const char* get_month_name(int month) {
    const char* months[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    return months[month - 1];
}

// Menghitung hari dalam minggu (Algoritma Zeller's Congruence)
const char* get_day_of_week(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int f = day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    return days_of_week[f % 7];
}

// Menghitung jumlah hari Minggu dalam setahun
int count_sundays_in_year(int year) {
    int count = 0;
    for (int month = 1; month <= 12; month++) {
        if (get_day_of_week(1, month, year) == days_of_week[0]) {
            count++;
        }
    }
    return count;
}

int main() {
    int mm, dd, yy, days_left_to_add;

    printf("Masukkan tanggal (mm dd yy) dan jumlah hari yang ingin ditambah: ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);

    // Tambahkan hari ke tanggal yang diinput
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("Tanggal baru: %s %d, %d\n", get_month_name(mm), dd, yy);

    // Cari tahu hari apa itu
    const char* day_of_week = get_day_of_week(dd, mm, yy);
    printf("Hari: %s\n", day_of_week);

    // Hitung jumlah hari Minggu dalam setahun
    int sundays = count_sundays_in_year(yy);
    printf("Jumlah hari Minggu di tahun %d: %d\n", yy, sundays);

    return 0;
}
