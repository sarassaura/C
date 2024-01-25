#include <limits.h>
#include <stdio.h>

unsigned long unsigned_convert(int size);

unsigned long half(int size);

int main() {
    /*
    printf("The range of signed char is:    -%lu to %lu\n", half(sizeof(char)), half(sizeof(char)) - 1);
    printf("The range of signed short is:   -%lu to %lu\n", half(sizeof(short)), half(sizeof(short)) - 1);
    printf("The range of signed int is:     -%lu to %lu\n", half(sizeof(int)), half(sizeof(int)) - 1);
    printf("The range of signed long is:    -%lu to %lu\n", half(sizeof(long)), half(sizeof(long)) - 1);
    */
    printf("The range of signed char is:    %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("The range of signed short is:   %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("The range of signed int is:     %d to %d\n", INT_MIN, INT_MAX);
    printf("The range of signed long is:    %ld to %ld\n", LONG_MIN, LONG_MAX);

    printf("\n");

    /*
    printf("The range of unsigned char is:  0 to %lu\n", unsigned_convert(sizeof(char)));
    printf("The range of unsigned short is: 0 to %lu\n", unsigned_convert(sizeof(short)));
    printf("The range of unsigned int is:   0 to %lu\n", unsigned_convert(sizeof(int)));
    printf("The range of unsigned long is:  0 to %lu\n", unsigned_convert(sizeof(long)));
    */
    printf("The range of unsigned char is:  0 to %d\n", UCHAR_MAX);
    printf("The range of unsigned short is: 0 to %d\n", USHRT_MAX);
    printf("The range of unsigned int is:   0 to %ld\n", UINT_MAX);
    printf("The range of unsigned long is:  0 to %lu\n", ULONG_MAX);

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