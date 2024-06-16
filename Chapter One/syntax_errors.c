#include <stdio.h>

int main() {
    int c = 0, open_paren = 0, closed_paren = 0, open_brackets = 0, closed_brackets = 0, open_braces = 0,
        closed_braces = 0;

    c = getchar();

    while (c != EOF) {

        while (c != 10 && c != EOF) {

            if (c == 34) {
                c = getchar();

                while (c != 34 && c != EOF && c != 10) {
                    c = getchar();
                }

                if (c == EOF || c == 10) {
                    break;
                }
            }

            if (c == 39) {
                c = getchar();

                while (c != 39 && c != EOF && c != 10) {
                    c = getchar();
                }

                if (c == EOF || c == 10) {
                    break;
                }
            }

            if (c == '/') {
                c = getchar();

                if (c == '/') {
                    c = getchar();

                    while (c != 10 && c != EOF) {
                        c = getchar();
                    }

                    if (c == EOF || c == 10) {
                        break;
                    }
                }

                if (c == '*') {
                    c = getchar();

                    while (c != EOF && c != 10) {
                        if (c == '*') {
                            c = getchar();

                            if (c == '/') {
                                c = getchar();
                                break;
                            }
                        }
                        c = getchar();
                    }

                    if (c == EOF || c == 10) {
                        break;
                    }
                }
            }

            switch (c) {
                case '(':
                    ++open_paren;
                    break;
                case ')':
                    ++closed_paren;
                    break;
                case '[':
                    ++open_brackets;
                    break;
                case ']':
                    ++closed_brackets;
                    break;
                case '{':
                    ++open_braces;
                    break;
                case '}':
                    ++closed_braces;
                    break;
            }

            c = getchar();
        }

        if (c == 10) {
            if (open_paren != closed_paren) {
                printf("Unmatched parentheses\n");
            }
            if (open_brackets != closed_brackets) {
                printf("Unmatched brackets\n");
            }
            if (open_braces != closed_braces) {
                printf("Unmatched braces\n");
            }

            open_paren = 0, closed_paren = 0, open_brackets = 0, closed_brackets = 0, open_braces = 0,
            closed_braces = 0;

            c = getchar();
        }
    }

    return 0;
}