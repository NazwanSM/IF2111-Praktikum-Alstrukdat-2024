#include <stdio.h>
#include "stack.h"
#include "stackchar.h"

int main(){
    int val;
    char opr;
    long long int tot = 0;
    StackChar SC;
    Stack S;

    CreateEmptyChar(&SC);
    CreateEmpty(&S);


    while(true){
        scanf("%c", &opr);
        if(opr == '='){
            break;
        }
        PushChar(&SC, opr);

        switch (opr){
            case '+':
                scanf("%d", &val);
                Push(&S, val);
                tot += val;
                break;
            case '-':
                scanf("%d", &val);
                Push(&S, -val);
                tot -= val;
                break;
            case 'u':
                if (!IsEmptyChar(SC)) {
                    char tempC;
                    int temp;
                    PopChar(&SC, &tempC);
                    Pop(&S, &temp);
                    tot -= temp;
                }
                break;

            default:
                break;
        }
    }
    printf("%lld\n",tot);
    return 0;
}