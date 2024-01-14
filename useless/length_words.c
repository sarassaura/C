#include <stdio.h>

int main() {
    int c = -10;
    int length[25];
    int letters = 0;

    for (int i = 0; i < 25; i++) {
        length[i] = 0;
    }

    while (c != EOF) {
        c = getchar();

        while (c != 10) {
            while (c != 9 && c != 32 && c != 10) {
                ++letters;
                c = getchar();
            }

            ++length[letters];
            letters = 0;

            if (c != 10) {
                c = getchar();
            }
        }

        for (int i = 1; i < 25; i++) {
            if (length[i] != 0) {
                printf("%2d word(s) with length: %2d \n", length[i], i);
            }
        }

        for (int i = 0; i < 25; i++) {
            length[i] = 0;
        }
    }

    return 0;
}