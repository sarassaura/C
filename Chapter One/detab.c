#include <stdio.h>
#define TAB 8

int print_tab(int i);

int main() {
    int c = 0, i = 0;

    c = getchar();

    while (c != EOF) {
        while (c != 10 && c != EOF) {
            if (c == 9) {
                i += print_tab(i);
            } else {
                putchar(c);
                ++i;
            }
            c = getchar();
        }

        if (c == 10) {
            putchar(10);
            c = getchar();
        }

        i = 0;
    }

    return 0;
}

int print_tab(int i) {
    int spaces = 0;

    spaces = TAB - ((i + 1) % TAB);

    for (int k = 0; k < spaces; k++) {
        putchar(32);
    }

    return spaces;
}
