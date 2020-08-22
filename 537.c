#include <stdio.h>

int main() {
    int val[100];
    double valuse[3];
    int testcase, status = 0;
    char ch, pch;
    register int t = 0, apos, ft;

    scanf("%d%^c", &testcase);

    while (t < testcase) {
        apos = ft = 0;
        scanf("%c", &ch);
        while (ch != '\n') {
            if (status == 0) {
                if (ch == 73) {
                    pch = ch;
                    scanf("%c", &ch);
                    if (ch == 61) {
                        status = 1;
                        ft += 0;
                    } else continue;
                } else if (ch == 85) {
                    pch = ch;
                    scanf("%c", &ch);
                    if (ch == 61) {
                        status = 1;
                        ft += 1;
                    } else continue;
                } else if (ch == 80) {
                    pch = ch;
                    scanf("%c", &ch);
                    if (ch == 61) {
                        status = 1;
                        ft += 2;
                    } else continue;
                }
            } else {
                int has_minus = 0;
                if (ch == 45) {
                    has_minus = 1;
                    scanf("%c", &ch);
                }
                if (ch > 47 && ch < 58) {
                    while (ch > 47 && ch < 58) {
                        val[apos++] = ch - 48;
                        scanf("%c", &ch);
                    }
                    register double num = 0.0, dec = 1.0;
                    while (apos--) {
                        num += (val[apos] * dec);
                        dec *= 10.0;
                    }
                    if (ch == 46) {
                        dec = .1;
                        scanf("%c", &ch);
                        while (ch > 47 && ch < 58) {
                            num += (ch - 48) * dec;
                            dec /= 10;
                            scanf("%c", &ch);
                        }
                    }
                    if (ch == 109) {
                        num *= 0.001;
                    } else if (ch == 107) {
                        num *= 1000;
                    } else if (ch == 77) {
                        num *= 1000000;
                    }

                    if (has_minus) num = -num;
                    if (pch == 73) {
                        valuse[0] = num;
                    } else if (pch == 85) {
                        valuse[1] = num;
                    } else if (pch == 80) {
                        valuse[2] = num;
                    }
                    apos = 0;
                } else {
                    status = 0;
                }
                continue;
            }
            scanf("%c", &ch);
        }

        if (ft == 1) {
            printf("Problem #%d\nP=%.2fW\n\n", ++t, valuse[0] * valuse[1]);
        } else if (ft == 2) {
            printf("Problem #%d\nU=%.2fV\n\n", ++t, valuse[2] / valuse[0]);
        } else if (ft == 3) {
            printf("Problem #%d\nI=%.2fA\n\n", ++t, valuse[2] / valuse[1]);
        }
    }


    return 0;
}
