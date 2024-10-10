#include <stdio.h>

int main() {
    int N;
    int bil;
    int arr[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &bil);
        arr[i] = bil;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("%d\n", arr[1]);
    return 0;
}