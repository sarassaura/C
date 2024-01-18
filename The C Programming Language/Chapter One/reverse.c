#include <stdio.h>
#define MAX 1000

void reverse(char s[], int i);
void reset(char s[]);

int main() {
    int c = 0, i = 0;
    char text[MAX];

    printf("Press Ctrl+d to end of file on the new line\n\n");

    while (c != EOF) {
        reset(text);
        i = 0;
        c = getchar();

        while (c != 10 && c != EOF && i < MAX - 1) {
            text[i] = c;
            c = getchar();
            ++i;
        }

        reverse(text, i);

        printf("\n%s\n\n", text);
    }

    return 0;
}

void reverse(char s[], int length) {
    char r[length];

    for (int i = 0; i < length; i++) {
        r[i] = s[length - 1 - i];
    }

    for (int i = 0; i < length; i++) {
        s[i] = r[i];
    }
}

void reset(char s[]) {
    for (int i = 0; i < MAX; i++) {
        s[i] = 0;
    }
}