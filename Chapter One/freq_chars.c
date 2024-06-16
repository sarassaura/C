#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    int c;
    int chars[129];
    int freq[129];
    int columns;
    int lines;

    while (c != EOF) {
        printf("\n");

        c = getchar();
        columns = lines = 0;

        for (int i = 0; i < 129; i++) {
            chars[i] = 0;
            freq[i] = 0;
        }

        while (c != 10 && c != EOF) {
            ++chars[c];
            c = getchar();
        }

        printf("\n");

        for (int i = 1; i < 129; i++) {
            if (chars[i] != 0) {
                printf("Char %c: ", i);
                for (int j = 0; j < chars[i]; j++) {
                    printf("%lc", (wint_t)9646);
                }
                printf(" %d charactere(s)\n", chars[i]);
            }
        }

        printf("\n");

        for (int i = 0; i < 129; i++) {
            if (chars[i] != 0) {
                freq[columns] = i;
                if (chars[i] > lines) {
                    lines = chars[i];
                }
                ++columns;
            }
        }

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++) {
                if (chars[freq[j]] == (lines - i)) {
                    printf("%lc", (wint_t)9608);
                    printf("%lc", (wint_t)9608);
                    printf("%lc", (wint_t)9608);
                    --chars[freq[j]];
                } else {
                    printf("%lc", (wint_t)9617);
                    printf("%lc", (wint_t)9617);
                    printf("%lc", (wint_t)9617);
                }
            }
            printf("\n");
        }

        if (freq[0] != 0) {
            printf("%2c", freq[0]);
        }

        for (int i = 1; i < columns; i++) {
            printf("%3c", freq[i]);
        }

        printf("\n");
    }
    return 0;
}