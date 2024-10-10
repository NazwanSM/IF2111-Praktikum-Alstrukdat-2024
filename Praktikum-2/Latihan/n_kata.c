#include <stdio.h>

int main() {
    char str[101];
    int i = 0;
    int counter = 1;
    
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            counter++;
        }
        i++;
    }
    printf("%d\n", counter);
    return 0;
}