#include <stdio.h>
#define MAXLINE 10

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    for (int i = 0; i < MAXLINE; i++) {
        line[i] = 0;
        longest[i] = 0;
    }

    max = 0;

    printf("Enter Ctrl+d to End Of File (at the beggning of line)\n\n");

    len = getLine(line, MAXLINE);

    while (len > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        for (int i = 0; i < MAXLINE; i++) {
            line[i] = 0;
        }
        len = getLine(line, MAXLINE);
    }

    if (max > 0) {
        printf("\nThe biggest line is (%d characteres):\n", max);
        printf("%s\n", longest);
    }
    return 0;
}

int getLine(char s[], int lim) {
    int c = -123, i = 0, t = 0;

    if (c != EOF) {
        c = getchar();
    }
    while (c != 10 && c != EOF) {
        if (i < lim - 2) {
            s[i] = c;
            ++t;
        }
        ++i;
        c = getchar();
    }

    if (c == 10) {
        s[t] = '\n';
        ++t;
        ++i;
    }
    s[t] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}