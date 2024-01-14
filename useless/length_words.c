#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    int c = -10;
    int length[25];
    int freq[25];
    int letters = 0;
    char result[] = "\0";
    int columns = 0;
    int lines = 0;

    for (int i = 0; i < 25; i++) {
        length[i] = 0;
        freq[i] = 0;
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
            if (length[i] != 0) {
                freq[columns] = i;
                if (length[i] > lines) {
                    lines = length[i];
                }
                ++columns;
            };
        }

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++) {
                if (length[freq[j]] == (lines - i)) {
                    printf("%lc", (wint_t)9608);
                    printf("%lc", (wint_t)9608);
                    printf("%lc", (wint_t)9608);
                    --length[freq[j]];
                } else {
                    printf("%lc", (wint_t)9617);
                    printf("%lc", (wint_t)9617);
                    printf("%lc", (wint_t)9617);
                }
            }
            printf("\n");
        }

        if (freq[0] != 0) {
            printf("%2d", freq[0]);
        }

        for (int i = 1; i < columns; i++) {
            printf("%3d", freq[i]);
        }

        printf("\n");

        for (int i = 0; i < 25; i++) {
            length[i] = 0;
        }
    }

    return 0;
}