#include <stdio.h>

int main() {
    int c;

    c = getchar();

    while (c != EOF) {
        while (c != ' ' && c != '\n' && c != '\t' && c != EOF) {
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