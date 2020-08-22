#include <stdio.h>

int main() {

    int keywords[20][21], raw_excuses[20][71], excuses[20][70], word_lengths[20][36], frequencies[20], total_keywords, total_excuses, excuse_set = 0;

    while (scanf("%d %d\n", &total_keywords, &total_excuses) == 2) {
        int t = 0, l = 0, n = 0;
        register int i = 0, j = 0, c = 0;
        while (t < total_keywords) {
            i = 0, c = 0;
            while ((c = getchar()) != 10) {
                keywords[t][i] = c;
                ++i;
            }
            keywords[t][20] = i;
            ++t;
        }
        t = 0;
        while (t < total_excuses) {
            frequencies[t] = 0;
            i = 0, c = 0, l = 0, n = 0;
            while ((c = getchar())) {
                if (c > 96 && c < 123) {
                    excuses[t][l] = c;
                    raw_excuses[t][j] = c;
                    ++i;
                    ++l;
                } else if (c > 64 && c < 91) {
                    excuses[t][l] = c + 32;
                    raw_excuses[t][j] = c;
                    ++i;
                    ++l;
                } else if (c == 10) {
                    raw_excuses[t][70] = j;
                    j = 0;
                    if (i > 0) {
                        word_lengths[t][n] = i;
                        ++n;
                        i = 0;
                    }
                    word_lengths[t][35] = n;
                } else {
                    raw_excuses[t][j] = c;
                    if (i > 0) {
                        word_lengths[t][n] = i;
                        i = 0;
                        ++n;
                    }
                }
                if (c == 10 || c == EOF) {
                    break;
                }
                ++j;
            }
            ++t;
        }
        int max_freq = 0;
        t = 0;
        while (t < total_excuses) {
            for (j = 0; j < total_keywords; ++j) {
                n = 0, l = 0;
                while (n < word_lengths[t][35]) {
                    if (keywords[j][20] == word_lengths[t][n]) {
                        i = 0;
                        while (keywords[j][i] == excuses[t][l + i] && i < keywords[j][20]) {
                            ++i;
                        }
                        if (i == word_lengths[t][n]) {
                            ++frequencies[t];
                        }
                    }
                    l += word_lengths[t][n];
                    ++n;
                }
            }
            if (frequencies[t] > max_freq) {
                max_freq = frequencies[t];
            }
            ++t;
        }
        printf("Excuse Set #%d\n", ++excuse_set);
        for (t = 0; t < total_excuses; ++t) {
            if (frequencies[t] == max_freq) {
                for (i = 0; i < raw_excuses[t][70]; ++i) {
                    putchar(raw_excuses[t][i]);
                }
                putchar(10);
            }
        }
        putchar(10);
    }
    return 0;
}
