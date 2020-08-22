#include <stdio.h>

char words[16][10] = {
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "Rujia",
        "Happy",
        "birthday",
        "to",
        "you",

};
int names[105][105];

int main() {
    int n, c;
    register int i = 0, j = 0;
    scanf("%d\n", &n);
    while (i < n - 1) {
        while ((c = getchar()) != 10) {
            names[i][j] = c;
            ++j;
        }
        names[i][j] = 10;
        ++i;
        j = 0;
    }
    while ((c = getchar()) != EOF && c != 10) {
        names[i][j] = c;
        ++j;
    }
    names[i][j] = 10;
    if (n >= 16) {
        for (i = 0; i < n; ++i) {
            j = 0;
            while (names[i][j] != 10)putchar(names[i][j++]);
            printf(": ");
            j = 0;
            while (words[i % 16][j])putchar(words[i % 16][j++]);
            putchar(10);
        }
        int k = (n % 16);
        for (i = k; i < 16; ++i) {
            j = 0;
            while (names[i - k][j] != 10)putchar(names[i - k][j++]);
            printf(": ");
            j = 0;
            while (words[i][j])putchar(words[i][j++]);
            putchar(10);
        }
    } else {
        for (i = 0; i < 16; ++i) {
            j = 0;
            while (names[i % n][j] != 10)putchar(names[i % n][j++]);
            printf(": ");
            j = 0;
            while (words[i][j])putchar(words[i][j++]);
            putchar(10);
        }
    }
    return 0;
}
