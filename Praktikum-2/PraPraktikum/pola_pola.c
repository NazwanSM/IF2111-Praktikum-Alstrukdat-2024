#include <stdio.h>

int main() {
    char str1[101];
    char str2[101];
    int pola = 1;

    scanf("%s", str1);
    scanf("%s", str2);
    for (int i = 0; i < 101; i++) {
        if (str1[i] == '\0') {
            break;
        }
        if (str1[i] == str2[i] || str1[i] == '*') {
            continue;
        } else {
            pola = 0;
            break;
        }
    }
    printf("%d\n", pola);
    return 0;
}