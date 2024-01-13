#include <stdio.h>

/*
    Tab - 9
    Backspace - 8 Ctrl+v + Ctrl+h
    Backslash - 92
*/

int main() {
    int c;

    c = getchar();

    while (c != EOF) {
        switch (c) {
        case 9:
            putchar(92);
            putchar(116);
            break;
        case 8:
            putchar(92);
            putchar(98);
            break;
        case 92:
            putchar(92);
            putchar(92);
            break;
        default:
            putchar(c);
        }
        c = getchar();
    }

    return 0;
}