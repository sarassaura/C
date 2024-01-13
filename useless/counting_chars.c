#include <stdio.h>

int main() {
    int c, line, tab, blank;
    c = line = tab = blank = 0;

    c = getchar();

    while (c != EOF) {
        switch (c) {
        case '\n':
            ++line;
            break;
        case '\t':
            ++tab;
            break;
        case ' ':
            ++blank;
            break;
        }
        printf("Lines: %d, Tabs: %d, Blanks: %d.\n", line, tab, blank);
        c = getchar();
    }
    return 0;
}