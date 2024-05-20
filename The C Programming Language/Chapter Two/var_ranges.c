#include <float.h>
#include <limits.h>
#include <stdio.h>

unsigned long unsigned_convert(int size);

unsigned long half(int size);

long double pow2(int bits);

float fl();

double dfl();

long double ldfl();

int main() {

    printf("The range of signed char is:          -%lu to %lu\n", half(sizeof(char)), half(sizeof(char)) - 1);
    printf("The range of signed short is:         -%lu to %lu\n", half(sizeof(short)), half(sizeof(short)) - 1);
    printf("The range of signed int is:           -%lu to %lu\n", half(sizeof(int)), half(sizeof(int)) - 1);
    printf("The range of signed long is:          -%lu to %lu\n", half(sizeof(long)), half(sizeof(long)) - 1);
    printf("The range of signed float is:         -%.1e to %.1e\n", fl(), fl());
    printf("The range of signed double is:        -%.3e to %.3e\n", dfl(), dfl());
    printf("The range of signed long double is:   -%.4Le to %.4Le\n", ldfl(), ldfl());

    // printf("The range of signed char is:    %d to %d\n", CHAR_MIN, CHAR_MAX);
    // printf("The range of signed short is:   %d to %d\n", SHRT_MIN, SHRT_MAX);
    // printf("The range of signed int is:     %d to %d\n", INT_MIN, INT_MAX);
    // printf("The range of signed long is:    %ld to %ld\n", LONG_MIN, LONG_MAX);
    // printf("The range of signed float is:   %.1e to %.1e with %d digits of precision\n", -FLT_MAX, FLT_MAX, FLT_DIG);
    // printf("The range of signed double is:  %.1e to %.1e with %d digits of precision\n", -DBL_MAX, DBL_MAX, DBL_DIG);
    // printf("The range of signed long double is:  %Le to %Le with %d digits of precision\n", -LDBL_MAX, LDBL_MAX,
    //        LDBL_DIG);

    printf("\n");

    printf("The range of unsigned char is:  0 to %lu\n", unsigned_convert(sizeof(char)));
    printf("The range of unsigned short is: 0 to %lu\n", unsigned_convert(sizeof(short)));
    printf("The range of unsigned int is:   0 to %lu\n", unsigned_convert(sizeof(int)));
    printf("The range of unsigned long is:  0 to %lu\n", unsigned_convert(sizeof(long)));

    // printf("The range of unsigned char is:  0 to %d\n", UCHAR_MAX);
    // printf("The range of unsigned short is: 0 to %d\n", USHRT_MAX);
    // printf("The range of unsigned int is:   0 to %ld\n", UINT_MAX);
    // printf("The range of unsigned long is:  0 to %lu\n", ULONG_MAX);

    return 0;
}

long double pow2(int bits) {

    long double range = 1;

    if (bits < 0) {
        bits *= -1;
        for (int i = 0; i < bits; i++) {
            range *= 0.5;
        }
    } else {
        for (int i = 0; i < bits; i++) {
            range *= 2;
        }
    }

    return range;
}

unsigned long unsigned_convert(int size) {
    int bits = size * 8;

    return pow2(bits) - 1;
}

unsigned long half(int size) {
    int bits = size * 8;

    return pow2(bits - 1);
}

float fl() { return pow2(127) * (2 - pow2(-23)); }

double dfl() { return pow2(1023) * (2 - pow2(-52)); }

long double ldfl() {
    long double exp = pow2(16383);
    long double res = 0;

    res -= exp / 51922968585348276;
    res += exp;
    res += exp;

    return res;
}