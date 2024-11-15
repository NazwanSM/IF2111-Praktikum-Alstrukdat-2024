#include <stdio.h>
#include "stack.h"

int main(){
    int N;
    scanf("%d", &N);
    infotype str[N];
    scanf("%s", str);

    Stack temp;
    CreateEmpty(&temp);
    int i = 0, count1 = 0, count2 = 0, cc = 0;


    while(str[i] != '\0') {
        Push(&temp, str[i]);
        i++;
    }

    char tempArr[N];
    i = 0;

    while(!IsEmpty(temp)){
        infotype chara;
        Pop(&temp, &chara);
        tempArr[i] = chara;
        i++;
    }

    int foundGreater = 0; 
    for(int j = 0; j < i; j++) {
        if(tempArr[j] == '>') {
            count1++;
            foundGreater = 1;
        }
        else if(tempArr[j] == '<' && foundGreater) {
            count2++;
        }
    }


    if (count1 == 0 || count2 == 0){
        printf("\n");
        return 0;
    }
    else if (count1 >= count2){
        while(count2 != 0){
            printf("<>");
            count2--;
        } 
        printf("\n");
    }
    else if (count1 < count2){
        while(count1 != 0){
            printf("<>");
            count1--;
        } 
        printf("\n");
    }
    return 0;
}