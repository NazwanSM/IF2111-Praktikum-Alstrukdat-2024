#include <stdio.h>

int fibonacci(int n);


int fibonacci(int n) {
    int arr[50];
    arr[0] = 1;
    arr[1] = 1;
    int count = 0;

    for (int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2]; 
    }

    for (int i = 0; i < n; i++) {
        if (arr[i]%2 == 0) {
            count += arr[i];
        }
    }
    return count;
}

int main() {
    int n;

    scanf("%d", &n);

    int count = fibonacci(n);
    if ( n < 1 || n > 50) {
        count = -1;
        printf("%d\n", count);
        return 0;
    }
    else {
        printf("%d\n", count);
    }

    return 0;
}