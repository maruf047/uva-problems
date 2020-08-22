#include <stdio.h>

int main() {
    int m, n, c, b;
    int power[20];
    register int t=0;
    scanf("%d %d %d", &n, &m, &c);
    while (n != 0 || m != 0 || c != 0) {
        b = 0;
        int fuse[20] = {0};
        register int i = 0, p = 0, max =0;
        while (i < n) {
            scanf("%d", &power[i++]);
        }
        i=0;
        while (i < m) {
            int x;
            scanf("%d", &x);
            x--;
            if (b == 0) {
                if (fuse[x] == 0) {
                    p+=power[x];
                    fuse[x]=1;
                    if(p>c){
                        b = 1;
                    }else{
                        if(p>max)max = p;
                    }
                } else {
                    p-=power[x];
                    fuse[x]=0;
                }
            }
            ++i;
        }
        if(b==0){
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",++t,max);
        }else{
            printf("Sequence %d\nFuse was blown.\n\n",++t);
        }
        scanf("%d %d %d", &n, &m, &c);
    }
    return 0;
}
