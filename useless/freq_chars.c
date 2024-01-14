#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    int c;
    int chars[128];
    int freq[128];
    int columns;
    int lines;

    while (c != EOF) {
        c = getchar();
        columns = lines = 0;

        for (int i = 0; i < 128; i++) {
            chars[i] = 0;
            freq[i] = 0;
        }

        while (c != 10) {
            ++chars[c];
            c = getchar();
        }

        for (int i = 0; i < 128; i++) {
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