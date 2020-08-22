#include <stdio.h>

int main() {
    int a, b, c, d, e, f, g, h, i;
    while (scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i) == 9) {
        register int x = 0;
        if (a != 0) {
            if (a != 1 && a != -1) {
                printf("%dx^8", a);
            } else {
                if (a == -1) {
                    printf("-x^8");
                } else {
                    printf("x^8");
                }
            }
            x = 1;
        }
        if (b != 0) {
            if (x == 0) {
                if (b != 1 && b != -1) {
                    printf("%dx^7", b);
                } else {
                    if (b == -1) {
                        printf("-x^7");
                    } else {
                        printf("x^7");
                    }
                }
            } else {
                if (b != 1 && b != -1) {
                    if (b > 0) {
                        printf(" + %dx^7", b);
                    } else {
                        printf(" - %dx^7", -b);
                    }
                } else {
                    if (b == -1) {
                        printf(" - x^7");
                    } else {
                        printf(" + x^7");
                    }
                }
            }
            x = 1;
        }
        if (c != 0) {
            if (x == 0) {
                if (c != 1 && c != -1) {
                    printf("%dx^6", c);
                } else {
                    if (c == -1) {
                        printf("-x^6");
                    } else {
                        printf("x^6");
                    }
                }
            } else {
                if (c != 1 && c != -1) {
                    if (c > 0) {
                        printf(" + %dx^6", c);
                    } else {
                        printf(" - %dx^6", -c);
                    }
                } else {
                    if (c == -1) {
                        printf(" - x^6");
                    } else {
                        printf(" + x^6");
                    }
                }
            }
            x = 1;
        }
        if (d != 0) {
            if (x == 0) {
                if (d != 1 && d != -1) {
                    printf("%dx^5", d);
                } else {
                    if (d == -1) {
                        printf("-x^5");
                    } else {
                        printf("x^5");
                    }
                }
            } else {
                if (d != 1 && d != -1) {
                    if (d > 0) {
                        printf(" + %dx^5", d);
                    } else {
                        printf(" - %dx^5", -d);
                    }
                } else {
                    if (d == -1) {
                        printf(" - x^5");
                    } else {
                        printf(" + x^5");
                    }
                }
            }
            x = 1;
        }
        if (e != 0) {
            if (x == 0) {
                if (e != 1 && e != -1) {
                    printf("%dx^4", e);
                } else {
                    if (e == -1) {
                        printf("-x^4");
                    } else {
                        printf("x^4");
                    }
                }
            } else {
                if (e != 1 && e != -1) {
                    if (e > 0) {
                        printf(" + %dx^4", e);
                    } else {
                        printf(" - %dx^4", -e);
                    }
                } else {
                    if (e == -1) {
                        printf(" - x^4");
                    } else {
                        printf(" + x^4");
                    }
                }
            }
            x = 1;
        }
        if (f != 0) {
            if (x == 0) {
                if (f != 1 && f != -1) {
                    printf("%dx^3", f);
                } else {
                    if (f == -1) {
                        printf("-x^3");
                    } else {
                        printf("x^3");
                    }
                }
            } else {
                if (f != 1 && f != -1) {
                    if (f > 0) {
                        printf(" + %dx^3", f);
                    } else {
                        printf(" - %dx^3", -f);
                    }
                } else {
                    if (f == -1) {
                        printf(" - x^3");
                    } else {
                        printf(" + x^3");
                    }
                }
            }
            x = 1;
        }
        if (g != 0) {
            if (x == 0) {
                if (g != 1 && g != -1) {
                    printf("%dx^2", g);
                } else {
                    if (g == -1) {
                        printf("-x^2");
                    } else {
                        printf("x^2");
                    }
                }
            } else {
                if (g != 1 && g != -1) {
                    if (g > 0) {
                        printf(" + %dx^2", g);
                    } else {
                        printf(" - %dx^2", -g);
                    }
                } else {
                    if (g == -1) {
                        printf(" - x^2");
                    } else {
                        printf(" + x^2");
                    }
                }
            }
            x = 1;
        }
        if (h != 0) {
            if (x == 0) {
                if (h != 1 && h != -1) {
                    printf("%dx", h);
                } else {
                    if (h == -1) {
                        printf("-x");
                    } else {
                        printf("x");
                    }
                }
            } else {
                if (h != 1 && h != -1) {
                    if (h > 0) {
                        printf(" + %dx", h);
                    } else {
                        printf(" - %dx", -h);
                    }
                } else {
                    if (h == -1) {
                        printf(" - x");
                    } else {
                        printf(" + x");
                    }
                }
            }
            x = 1;
        }
        if (i != 0) {
            if (x == 0) {
                if (i != 1 && i != -1) {
                    printf("%d", i);
                } else {
                    if (i == -1) {
                        printf("-1");
                    } else {
                        printf("1");
                    }
                }
            } else {
                if (i > 0) {
                    printf(" + %d", i);
                } else {
                    printf(" - %d", -i);
                }
            }
            x = 1;
        }
        if (x == 0) {
            putchar('0');
        }
        putchar('\n');
    }
    return 0;
}