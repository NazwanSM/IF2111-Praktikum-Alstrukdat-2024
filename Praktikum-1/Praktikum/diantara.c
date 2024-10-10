#include <stdio.h>

int main(){
    int L, R, D, i;
    int count = 0;

    scanf("%d %d %d", &L, &R, &D);
    if ((0 <= L <=1000000000) && (0 <= R <=1000000000) && (0 <= D <=1000000000)){
        if (L > R){
            int LR = L;
            L = R;
            R = LR;
        }
        
        i = R;
        while (i >= L){
            if (i%D == 0){
                count++;
            }
            i--;
        }
    }
    printf("%d\n", count);
    return 0;
}