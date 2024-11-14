#include <stdio.h>
#include "stack.h"

int main() {
    int Q, X, POI;
    Stack S;
    
    scanf("%d", &Q);
    CreateEmpty(&S);

    for(int i = 0; i < Q; i++) {
        scanf("%d", &POI);
        
        switch (POI) {
            case 1: 
                if (!IsFull(S)) {
                    scanf("%d", &X);
                    Push(&S, X);
                }
                break;
                
            case 2:
                if (!IsEmpty(S)) {
                    Pop(&S, &X);
                }
                break;
                
            case 3:
                if (!IsEmpty(S)) {
                    int maxVal = S.T[0];
                    int maxLantai = 1;
                    
                    for(int j = 0; j <= Top(S); j++) {
                        if(S.T[j] > maxVal) {
                            maxVal = S.T[j];
                            maxLantai = j + 1;
                        }
                    }
                    
                    printf("%d %d\n", maxLantai, maxVal);
                }
                break;
                
            default:
                break;
        }
    }
    return 0;
}
