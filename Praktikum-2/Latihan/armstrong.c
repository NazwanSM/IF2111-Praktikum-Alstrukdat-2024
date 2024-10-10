#include <stdio.h>

int length(int n);
int pangkat(int n, int x);

int length(int n) {
    int counter = 0;

    int temp = n;
    while(temp >= 1){
        temp /= 10;
        counter++;
    }
    return counter;
}


int pangkat(int n, int x) {
    int result = 1;
    for(int i = 0; i < x; i++){
        result *= n;
    }
    return result;
}

int main(){
    int X, Y;
    int len;
    int counter = 0;
    
    scanf("%d %d", &X, &Y);

    while(X <= Y) {
        len = length(X);
        int temp = X;
        int arr[length(X)];
        for(int i = len - 1; i >= 0; i--){
            arr[i] = temp%10;
            temp /= 10;
        }
        
        for (int i = 0; i < len; i++) {
            counter += pangkat(arr[i], len);
        }

        if (counter == X) {
            printf("%d\n", counter);
        }
        counter = 0;
        X++;
    }
    return 0;
}