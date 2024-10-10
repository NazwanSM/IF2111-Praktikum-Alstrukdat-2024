#include <stdio.h>

int main(){
    long long int n, m, r;
    int hasil[100000];
    scanf("%lld", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &m, &r);  
            int steps = m / r;
            if (steps % 2 == 0) {
                hasil[i] = 1;
            } else {
                hasil[i] = 0;
            }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", hasil[i]);
    }
    return 0;
}