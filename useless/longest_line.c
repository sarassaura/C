#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    printf("Enter Ctrl+d to End Of File (at the beggning of line)\n\n");

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("\nThe biggest line is (%d characteres):\n", max);
        printf("%s\n", longest);
    }
    return 0;
}

int getLine(char s[], int lim) {
    int c, i = 0;

    if (c != EOF) {
        c = getchar();
    }
    while (c != 10 && c != EOF && i < lim - 1) {
        s[i] = c;
        ++i;
        c = getchar();
    }

    if (c == 10) {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}