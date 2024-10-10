#include <stdio.h>

int length(int N);

int length(int N) {
    int temp, counter = 0; 
    temp = N;

    while (temp >= 1 ) {
        temp /= 10;
        counter ++;
    }
    return counter;
}

int main(){
    int N;
    int bil;
    int counter = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &bil);
        if(length(bil)%2 == 0) {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}