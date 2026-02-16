#include <stdio.h>

/*
 Function: reverseString
 Purpose : Reverses the given character array in-place
 Params  :
    s     -> character array
    size  -> length of the array
*/
void reverseString(char* s, int size) {
    int left = 0;
    int right = size - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char codeName[] = {'S','E','C','R','E','T'};
    int size = sizeof(codeName) / sizeof(codeName[0]);

    reverseString(codeName, size);

    printf("Mirror Code Name: ");
    for (int i = 0; i < size; i++) {
        printf("%c", codeName[i]);
    }

    return 0;
}