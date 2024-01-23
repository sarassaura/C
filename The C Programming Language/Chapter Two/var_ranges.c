#include <stdio.h>

unsigned long unsigned_convert(int size);

unsigned long half(int size);

int main() {
    printf("The range of signed char is:  -%lu to %lu\n", half(sizeof(char)), half(sizeof(char)) - 1);
    printf("The range of signed short is: -%lu to %lu\n", half(sizeof(short)), half(sizeof(short)) - 1);
    printf("The range of signed int is:   -%lu to %lu\n", half(sizeof(int)), half(sizeof(int)) - 1);
    printf("The range of signed long is:  -%lu to %lu\n", half(sizeof(long)), half(sizeof(long)) - 1);

    printf("\n");

    printf("The range of unsigned char is:  0 to %lu\n", unsigned_convert(sizeof(char)));
    printf("The range of unsigned short is: 0 to %lu\n", unsigned_convert(sizeof(short)));
    printf("The range of unsigned int is:   0 to %lu\n", unsigned_convert(sizeof(int)));
    printf("The range of unsigned long is:  0 to %lu\n", unsigned_convert(sizeof(long)));

    return 0;
}

unsigned long unsigned_convert(int size) {
    int bits = size * 8;
    unsigned long range = 1;

    for (int i = 0; i < bits; i++) {
        range *= 2;
    }

    return range - 1;
}

unsigned long half(int size) {
    int bits = size * 8;
    unsigned long range = 1;

    for (int i = 0; i < bits; i++) {
        range *= 2;
    }

    return (((range - 2) / 2) + 1);
}