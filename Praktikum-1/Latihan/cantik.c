#include <stdio.h>

const char* cantik(int a, int b);

int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%s\n", cantik(a, b));
    
    return 0;
}

const char* cantik(int a, int b){
    if((a + b)%4 == 0 || (a*b)%4 == 0){
        return "Y";
    } else {
        return "N";
    }
}