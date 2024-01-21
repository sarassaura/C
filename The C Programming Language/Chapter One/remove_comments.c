#include <stdio.h>

int main() {
    char *program = "#include <stdio.h>\n\n"
                    "// Celsius - Fahrenheint - Kelvin\n"
                    "/*\n"
                    "    1 to 100 Celsius\n"
                    "*/\n\n"
                    "float c_to_k(float n) { return n + 273.15; }\n\n"
                    "float c_to_f(float n) { return n * 9.0 / 5.0 + 32; }\n\n"
                    "int main() {\n"
                    "    printf(\"Celsius     Fahrenheint     Kelvin\\n\\n\");\n"
                    "    for (int i = 0; i <= 100; i++) {\n"
                    "        printf(\"%4d%16.2f%14.2f\\n\", i, c_to_f(i), c_to_k(i));\n"
                    "    }\n"
                    "    return 0;\n"
                    "}\n";

    int i = 0;

    while (program[i] != '\0') {

        if (program[i] == 34) {
            putchar(program[i]);
            ++i;

            while (program[i] != 34 && program[i + 1] != '\0') {
                putchar(program[i]);
                ++i;
            }
        }
        if (program[i] == 39) {
            putchar(program[i]);
            ++i;

            while (program[i] != 39 && program[i + 1] != '\0') {
                putchar(program[i]);
                ++i;
            }
        }
        if (program[i] == '/' && program[i + 1] != '\0' && program[i + 1] == '/') {
            while (program[i] != '\n' && program[i + 1] != '\0') {
                ++i;
            }
            if (program[i + 1] == '\0') {
                break;
            }
            while (program[i] == '\n') {
                ++i;
            }
        }
        if (program[i] == '/' && program[i + 1] != '\0' && program[i + 1] == '*') {
            while (program[i + 1] != '\0' && (program[i] != '*' || program[i + 1] != '/')) {
                ++i;
            }
            if (program[i + 1] != '\0') {
                i += 2;
            }
            while (program[i] == '\n') {
                ++i;
            }
        }

        putchar(program[i]);
        ++i;
    }

    return 0;
}