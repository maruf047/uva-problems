#include <stdio.h>

void ternary(long int n) {
    long int x = n/3;
    if (x>0) {
        int i = n%3;
        ternary(x);
        if(i==2){
            putchar('2');
        }else if(i==1){
            putchar('1');
        }else{
            putchar('0');
        }
    }else{
        int i = n%3;
        if(i==2){
            putchar('2');
        }else if(i==1){
            putchar('1');
        }else{
            putchar('0');
        }
    }
}

int main() {
    long int num;
    scanf("%ld", &num);
    while (num >= 0) {
        ternary(num);
        putchar('\n');
        scanf("%ld", &num);
    }
    return 0;
}