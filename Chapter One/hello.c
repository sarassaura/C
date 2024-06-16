#include <stdio.h>

int main() {
    char hello[] = "Hello";
    char world[] = {'W', 'o', 'r', 'l', 'd', '\0'};

    printf("The size of variable types are machine dependent:\n\n");
    printf("short: %d bytes\n", sizeof(short));
    printf("int: %d bytes\n", sizeof(int));
    printf("long: %d bytes\n", sizeof(long));
    printf("double: %d bytes\n", sizeof(double));
    printf("char: %d bytes\n", sizeof(char));
    printf("float: %d bytes\n", sizeof(float));
    printf("%s: %d bytes\n", hello, sizeof(hello));
    printf("%s: %d bytes\n\n", world, sizeof(world));
    printf("Strings will always have one more byte\n");
    printf("for the \\0 EOF (end of file)\n");
    return 0;
}