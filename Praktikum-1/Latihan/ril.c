#include <stdio.h>

int main () {
    int n;
    int counter = 1;

    scanf("%d", &n);
    while (counter<=n){
        if (counter%3 == 0 && counter%5 == 0){
            printf("RilNyata\n");
        }
        else if (counter%3 == 0){
            printf("Nyata\n");
        }
        else if (counter%5 == 0){
            printf("Ril\n");
        }
        else {
            printf("%d\n", counter);
        }
        counter++;
    }
}
