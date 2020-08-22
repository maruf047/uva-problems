#include <stdio.h>
#include <string.h>

int main() {
    char str[15];
    register int i, j;
    scanf("%s", str);
    i = 0;
    while (strcmp(str, "#") != 0) {
        i++;
        printf("Case %d: ", i);
        if (strcmp(str, "HELLO") == 0) printf("ENGLISH\n");
        else if (strcmp(str, "HOLA") == 0) printf("SPANISH\n");
        else if (strcmp(str, "HALLO") == 0) printf("GERMAN\n");
        else if (strcmp(str, "BONJOUR") == 0) printf("FRENCH\n");
        else if (strcmp(str, "CIAO") == 0) printf("ITALIAN\n");
        else if (strcmp(str, "ZDRAVSTVUJTE") == 0) printf("RUSSIAN\n");
        else printf("UNKNOWN\n");
        scanf("%s", str);
    }
    return 0;
}
