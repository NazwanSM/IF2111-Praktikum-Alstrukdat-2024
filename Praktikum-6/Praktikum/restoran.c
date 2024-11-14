#include <stdio.h>
#include "queue.h"

int main(){
    Queue que_time;
    CreateQueue(&que_time);

    int input, input_time, output_time, min_time, max_time;
    int c = 0;

    scanf("%d", &input);

    while (input != 0){
        if (input == 1 && !isFull(que_time)){
            scanf("%d", &input_time);
            
            if (input_time > 0){
                enqueue(&que_time, input_time);
            }
        }
        
        else if (input == 2 && !isEmpty(que_time)){
            dequeue(&que_time, &output_time);

            c += 1;

            if (c == 1){
                min_time = output_time;
                max_time = output_time;
            } 
            else{
                if (output_time < min_time){
                    min_time = output_time;
                } 
                else if (output_time > max_time){
                    max_time = output_time;
                }
            }
        }
        scanf("%d", &input);
    }
    
    printf("%d\n", c);
    printf("%d\n", min_time);
    printf("%d\n", max_time);
}