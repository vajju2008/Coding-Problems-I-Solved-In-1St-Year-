#include <stdio.h>
#include <string.h>

int main() {
    char S[6]; 
    scanf("%s", S);
    
    if (strcmp(S + 2, "nta") == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}