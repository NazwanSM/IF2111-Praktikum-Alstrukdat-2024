#include <stdio.h>

int main () {
    int n, c;
    int total=0, bil=0, count=0, i=0;

    scanf("%d", &n);
    c = n;
    while (c >= 1) {
            c /= 10;
            count++;
    }
    if(count%2 != 0){
        n/=10;
        count--;
    }

    while(count>i){
        bil = n%10;
        total += bil;
        n /= 100;
        i++;
    }
    printf("%d\n", total);
    return 0;
}