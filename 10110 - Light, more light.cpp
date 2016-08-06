#include <stdio.h>
#include <math.h>
int main() {
    unsigned long int n;
    scanf("%lu", &n);
    while (n!=0) {
        if((int)(sqrt(n))==sqrt(n)){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        scanf("%lu", &n);
    }
    return 0;
}
