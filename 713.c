#include <stdio.h>

int main() {
    int testcase;
    scanf("%d\n", &testcase);
    register int t = testcase;
    while (t--) {
        int a[201], b[201], flip = 1, la, lb;
        register int i = 0;
        char ch;
        while (ch = getchar()) {
            if (ch > 47 && ch < 58) {
                if (flip) {
                    a[i++] = ch - 48;
                } else {
                    b[i++] = ch - 48;
                }
            } else if (ch == 32) {
                flip = 0;
                la = i;
                i = 0;
            } else if (ch == 10 || ch == EOF) {
                int sum[202];
                register int c = 0, x;
                lb = i;
                if (la > lb) {
                    for (i = 0; i < la; ++i) {
                        if (i < lb) {
                            x = a[i] + b[i] + c;
                            if (x < 10) {
                                sum[i] = x;
                                c = 0;
                            } else {
                                sum[i] = x % 10;
                                c = 1;
                            }
                        } else {
                            x = a[i] + c;
                            if (x < 10) {
                                sum[i] = x;
                                c = 0;
                            } else {
                                sum[i] = x % 10;
                                c = 1;
                            }
                        }
                    }
                    if (c){
                        sum[i]=c;
                        la++;
                    }
                    i=0;
                    while(sum[i]==0)++i;
                    for (; i < la; ++i) {
                        putchar(sum[i] + 48);
                    }
                    putchar(10);
                } else {
                    for (i = 0; i < lb; ++i) {
                        if (i < la) {
                            x = a[i] + b[i] + c;
                            if (x < 10) {
                                sum[i] = x;
                                c = 0;
                            } else {
                                sum[i] = x % 10;
                                c = 1;
                            }
                        } else {
                            x = b[i] + c;
                            if (x < 10) {
                                sum[i] = x;
                                c = 0;
                            } else {
                                sum[i] = x % 10;
                                c = 1;
                            }
                        }
                    }
                    if (c){
                        sum[i]=c;
                        lb++;
                    }
                    i = 0;
                    while (sum[i] == 0)++i;
                    for (; i < lb; ++i) {
                        putchar(sum[i] + 48);
                    }
                    putchar(10);
                }
                break;
            }
        }
    }
    return 0;
}
