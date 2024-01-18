#include <stdio.h>

int main() {
    printf("EOF: %d\n\n", EOF);

    int c;

    c = getchar();

    while (c != EOF) {
        if (c != '\n') {
            printf("Character: %c, EOF: %d \n", c, c == EOF);
        }
        c = getchar();
    }

    // Press Ctrl+d for End of File.
    if (c == EOF) {
        printf("EOF: %d\n", c == EOF);
    }

    // if(0) evaluates to false
    // if(1) evaluates to true

    return 0;
}