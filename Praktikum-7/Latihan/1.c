#include <stdio.h>
#include "stack.h"

int main(){
    int n, x, op, a;

    scanf("%d", &n);
    char lagu[n][20];
    for (int i = 0; i < n; i++){
        scanf("%s", lagu[i]);
    }

    scanf("%d", &x);

    Stack S;
    CreateEmpty(&S);

    for (int i = 0; i < x; i++) {
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                scanf("%d", &a);
                Push(&S, a);
                printf("Playing: %s\n", lagu[a]);
                break;
            case 2:
                if (IsEmpty(S)){
                    printf("No music id played\n");
                }
                else {
                    int val;
                    Pop(&S, &val);
                    if(IsEmpty(S)){
                        printf("No music is played\n");
                    }
                    else{
                        printf("Playing: %s\n", lagu[Top(S)]);
                    }
                }
            default:
                break;
        }
    }
    return 0;
}