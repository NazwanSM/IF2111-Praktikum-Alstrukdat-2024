#include <stdio.h>

int main () {
    int a, b, c, big;

    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c){
        big = a;
    } else if (b > a && b > c){
        big = b;
    } else {
        big = c;
    }
    printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n", a, b, c, big);
    return 0;
}