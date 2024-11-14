#include "valid.h"


Stack validParantheses(char* input, int length) {
    Stack temp, valid;
    int i;

    CreateEmpty(&temp);
    CreateEmpty(&valid);

    for (i = 0; i < length; i++) {
        if (!IsEmpty(temp)) {
            if ((input[i] == ')' && InfoTop(temp) == '(') || (input[i] == '}' && InfoTop(temp) == '{') || (input[i] == ']' && InfoTop(temp) == '[')) {
                Push(&valid, InfoTop(temp));
                Push(&valid, input[i]);
            }
            else {
                Push(&temp, input[i]);
            }
        }
        else {
            Push(&temp, input[i]);
        }
    }
    return valid;
}
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/