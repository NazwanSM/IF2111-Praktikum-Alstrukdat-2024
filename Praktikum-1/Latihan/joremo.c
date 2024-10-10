#include <stdio.h>

int main () {
    int n, bil, i, angan;
    int total = 1, counter = 0, c = 0, cnt = 0, tot = 0;

    scanf("%d", &n);
    i = n;
    while (i > 1){
        i /= 10;
        counter++;
    } 

    while (counter > c){
        bil = n % 10;
        if (bil != 0){
            total *= bil;
        }
        n /= 10;
        c++;
    }
    printf("%d ", total);

    counter = 0;
    while (total > 1){
        if (total%10 != 0){
            counter++;
        }
        total /= 10;
    } 
    printf("%d\n", counter);
    return 0;
}