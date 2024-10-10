#include <stdio.h>

int main() {
    int kH, kM, kB;
    char W;
    int N;
    int HH = 0;
    int MM = 0;
    int BB = 0;

    scanf("%d %d %d", &kH, &kM, &kB);
    while (W != 'Z') {
        scanf("%c", &W);
        if (W == 'E') {
            break;
        } else {
            scanf(" %d", &N);
            if (W == 'H') {
                HH += N;
            } else if (W == 'M') {
                MM += N;
            } else if (W == 'B') {
                BB += N;        
            }        
        }
    }

    printf("%d %d %d\n", HH, MM, BB);
    if (HH > kH || MM > kM || BB > kB){
        printf("Tidak\n");
    } else if (HH == 0 && MM == 0 && BB == 0) {
        printf("Tidak\n");
    } else {
        printf("Ya\n");
    }
    return 0;
}