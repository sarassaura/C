#include <stdio.h>
#define MAX 10

void copy(char from[], char to[], int k, int l);
void reset(char s[]);
int transform(char line[], int i, char c);

int main() {
    int c = 0, i = 0, j = 0;
    char text[MAX];
    char line[MAX];

    printf("Press Ctrl+d to end of file on the new line\n\n");

    reset(text);

    while (c != EOF && j < MAX - 1) {
        c = getchar();
        // Reset line
        reset(line);
        // Get line
        while (c != 10 && c != EOF && (i + j) < MAX - 2) {
            line[i] = c;
            c = getchar();
            ++i;
        }
        // Transform line
        i = transform(line, i, c);
        // Copy Line
        copy(line, text, i, j);
        j += i;
        i = 0;
    }

    text[j] = '\0';

    printf("\n%s\n", text);
    return 0;
}

void copy(char from[], char to[], int k, int l) {
    for (int i = 0; i < k; i++) {
        to[l + i] = from[i];
    }
}

void reset(char s[]) {
    for (int i = 0; i < MAX; i++) {
        s[i] = 0;
    }
}

int transform(char line[], int i, char c) {
    int l = i;
    --l;

    while (line[l] == 32 || line[l] == 9) {
        --l;
    }

    if (c == EOF || c == 10) {
        ++l;
        line[l] = c;
    }

    return l + 1;
}