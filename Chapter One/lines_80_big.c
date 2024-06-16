#include <stdio.h>
#define MAX 10

void reset(char line[]);

int main() {
    char line[MAX];
    int c = 0;
    int length = 0;

    while (c != EOF) {
        c = getchar();
        reset(line);
        length = 0;

        while (c != EOF && c != 10) {
            line[length] = c;
            ++length;
            c = getchar();
        }

        if (length > 0 && length < MAX) {
            printf("%s\n\n", line);
        }
    }

    return 0;
}

void reset(char line[]) {
    for (int i = 0; i < MAX; i++) {
        line[i] = 0;
    }
}