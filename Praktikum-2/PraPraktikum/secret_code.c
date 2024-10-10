#include <stdio.h>
#include "secret_code.h"



int count_length(char str[]) {
    int i = 0;
    while (str[i] != '#') {
        i++;
    }
    return i;
}

void print_decrypted(char str[]) {
    int i = 0;
    int counter = 0;
    char temp[21] = {0};

    while (str[i] != '#') {
        if ((str[i] >= 'A' && str[i] <= 'Z' )||( str[i] >= 'a' && str[i] <= 'z')) {
            temp[counter] = str[i];
            counter ++;
        }
        i++;
    }

    if (counter == 0) {
        printf("\n");
        return;
    }

    temp[counter] = '\0';
    printf("%s\n", temp);
}