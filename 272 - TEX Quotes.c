#include <stdio.h>

int main()
{
    char c;
    register int true = 0;
    while((c=getchar())!=EOF){
        if(c!='"'){
            printf("%c",c);
        }else{
            if(true==0){
                printf("``");
                true = 1;
            }else{
                printf("''");
                true = 0;
            }
        }
    }
    return 0;
}
