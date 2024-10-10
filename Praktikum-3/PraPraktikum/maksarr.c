#include <stdio.h>

int max(int N, int arr[N]);

int max(int N, int arr[N]) {
    int Ans = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > Ans) {
            Ans = arr[i];
        }
    }
    return Ans;
}

int main() {
    int N;
    
    scanf("%d", &N);
    int arr[N];
    int index[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int maxValue = max(N, arr);
    int X = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] == maxValue) {
            index[X] = i;
            X++;
        }
    }

    printf("%d %d\n", maxValue, X);
    for (int i = 0; i < X; i++) {
        printf("%d ", index[i]);
    }
    printf("\n");
}
