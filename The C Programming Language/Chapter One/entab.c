#include <stdio.h>
#define TAB 4

int main() {
    int c = 0, i = 0, w = 0, tabs = 0;

    c = getchar();

    while (c != EOF) {

        while (c != 10 && c != EOF) {

            if (c == 32) {
                c = getchar();
                ++w;

                while (c == 32) {
                    if ((i + w) % TAB == 0) {
                        ++tabs;
                    }

                    c = getchar();
                    ++w;
                }

                if ((i + w) % TAB == 0) {
                    ++tabs;
                }

                for (int j = 0; j < tabs; j++) {
                    putchar(9);
                }

                for (int k = 0; k < ((i + w) % TAB); k++) {
                    putchar(32);
                }

                i += w;
            } else {
                putchar(c);
                c = getchar();
                ++i;
            }

            w = 0;
            tabs = 0;
        }

        if (c == 10) {
            putchar(10);
            c = getchar();
            ++i;
        }

        i = 0;
    }

    return 0;
}