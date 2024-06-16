#include <stdio.h>
#define MAX 5
#define TAB 4

void check(char line[], int i);
void reset(char line[]);
int print_tab(char line[], int i);

int main() {
    int c = 0, i = 0;
    char line[MAX];

    c = getchar();

    reset(line);

    while (c != EOF) {
        while (c != 10 && c != EOF) {

            if (c == 9) {
                i += print_tab(line, i);
            } else {
                line[i] = c;
                ++i;
            }

            c = getchar();

            if ((i % (MAX - 2)) == 0) {
                check(line, i);
                i = 0;
            }
        }

        if (c == 10) {
            check(line, i);
            c = getchar();
            i = 0;
        }
    }
    return 0;
}

void check(char line[], int i) {
    int k = i - 1;

    while (line[k] == 9 || line[k] == 32) {
        --k;
    }

    if (k > -1) {
        line[k + 1] = 10;
        line[k + 2] = '\0';
        printf("%s", line);
        reset(line);
    }
}

void reset(char line[]) {
    for (int i = 0; i < MAX; i++) {
        line[i] = 0;
    }
}

int print_tab(char line[], int i) {
    int spaces = 0, k = 0;

    spaces = TAB - ((i + 1) % TAB);

    for (k = 0; k < spaces && (k + i) < MAX; k++) {
        line[k + i] = 32;
    }

    return k;
}
