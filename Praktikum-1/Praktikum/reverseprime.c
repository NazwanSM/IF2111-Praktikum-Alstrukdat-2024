#include <stdio.h>


int main(){
    int a, hasil, n = 0, c;
    int bil = 0, i = 0;

    scanf("%d", &a);
    c = a;
    while(c>1){
        c /= 10;
        n++;
    }

    while (i<=n){
        bil = a%10;
        if (bil != 1 && bil != 4 && bil != 6 && bil != 8 && bil != 9 && bil != 0){
            hasil += bil;
            hasil *= 10;
        }
        a /= 10;
        i++;
        if (i == n && hasil != 0){
            hasil /= 10;
        }
    }
    printf("%d\n", hasil);
    return 0;
}