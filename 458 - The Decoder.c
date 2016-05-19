#include <stdio.h>

int main()
{
    char c;
    while((c=getchar())!=EOF){
        if(c!='\n')printf("%c",c-7);
        else printf("\n");
    }
    return 0;
}
