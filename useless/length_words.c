#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {
    setlocale(LC_CTYPE, "en_US.UTF-8");
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

        printf("\n");

        for (int i = 1; i < 25; i++) {
            if (length[i] != 0) {
                printf("length %d: ", i);
                for (int j = 0; j < length[i]; j++) {
                    printf("%lc", (wint_t)9646);
                }
                printf(" %d word(s)\n", length[i]);
            }
        }

        printf("\n");

        for (int i = 0; i < 25; i++) {
            length[i] = 0;
        }
    }

    return 0;
}