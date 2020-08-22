#include <stdio.h>

int main() {

    char sym[55] = {';', '*', '*', '*', '*', 'M', '0', ',', '.', '9', '`', '1', '2', '3', '4', '5', '6', '7', '8',
                    '*', 'L', '*', '-', '*', '*', '*', '*', 'V', 'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J',
                    'K', 'N', 'B', 'I', 'O', '*', 'E', 'A', 'R', 'Y', 'C', 'Q', 'Z', 'T', '*', 'P', ']', '['};
    char ch;
    while (scanf("%c", &ch) != EOF) {
        if (ch > 38 && ch < 94) {
            printf("%c", sym[ch - 39]);
        } else printf("%c", ch);
    }
    return 0;
}

