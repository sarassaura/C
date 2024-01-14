#include <stdio.h>

int main() {
    int c;
    int outWord = 0;

    c = getchar();

    while (c != EOF) {

        while (c != ' ' && c != '\n' && c != '\t') {
            putchar(c);
            c = getchar();
        }

        putchar('\n');

        while (c == ' ' || c == '\n' || c == '\t') {
            c = getchar();
        }
    }
    return 0;
}