#include <stdio.h>

#define gc getchar()

inline int read_int() {
    char c = gc;
    if (c == EOF)return -1;
    while (c < '0' || c > '9')
        c = gc;
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc;
    }
    return ret;
}

inline void write(int n) {
    char buffer[sizeof(n) * 8 * 3 / 10 + 3];
    int index = sizeof(buffer) - 1;
    int end = index;
    buffer[index--] = 0;
    do {
        buffer[index--] = (n % 10) + '0';
        n /= 10;
    } while (n);
    printf("%s", &buffer[index + 1]);
}

int main() {
    int m, n;
    m = read_int();
    while (m != -1) {
        n = read_int();
        write((m * n) - 1);
        putchar('\n');
        m = read_int();
    }
    return 0;
}
