#include <stdio.h>

int main() {
    int c;
    int blank = 0;

    c = getchar();

    while (c != EOF) {
        while (c == 32) {
            c = getchar();
            ++blank;
        }
        if (blank) {
            putchar(32);
            blank = 0;
        }
        putchar(c);
        if (c != EOF) {
            c = getchar();
        }
    }

    return 0;
}