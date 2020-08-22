#include <stdio.h>
#include <math.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    register int t = testcase;
    while (t--) {
        int l;
        scanf("%d", &l);
        double r = (1.0 / 5) * l;
        double ra = r * r * acos(-1);
        printf("%.2lf %.2lf\n", ra, ((1.0 * 3) / 5) * l * l - ra);
    }
    return 0;
}
