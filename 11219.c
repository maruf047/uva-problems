#include <stdio.h>

int main() {
    int testcase;
    int d1, d2, m1, m2, y1, y2;
    int age;
    register int t = 0;
    scanf("%d", &testcase);
    while (t < testcase) {
        scanf("%d/%d/%d", &d1, &m1, &y1);
        scanf("%d/%d/%d", &d2, &m2, &y2);
        if (y2 < y1) {
            age = y1 - y2;
            if (m2 > m1) {
                age--;
            } else if (m1 == m2) {
                if (d2 > d1) {
                    age--;
                }
            }
        } else if (y2 == y1) {
            age = y1 - y2;
            if (m1 == m2) {
                if (d2 > d1) {
                    printf("Case #%d: Invalid birth date\n", ++t);
                    continue;
                }
            } else if (m2 > m1) {
                printf("Case #%d: Invalid birth date\n", ++t);
                continue;
            }
        } else {
            printf("Case #%d: Invalid birth date\n", ++t);
            continue;
        }

        if (age > 130) {
            printf("Case #%d: Check birth date\n", ++t);
        } else {
            printf("Case #%d: %d\n", ++t, age);
        }
    }
    return 0;
}
