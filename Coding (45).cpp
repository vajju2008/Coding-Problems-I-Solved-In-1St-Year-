#include <stdio.h>

int main() {
    int t; // t is variablr 
    
    scanf("%d", &t);

    for (; t > 0; t--) {
        int n;
        scanf("%d", &n);

        int total = 0;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            total += v; // total 
        }

        int x = 0;
        if (total < 0) {
            int need = -total; // total 
            x = need / n;
            if (need % n != 0)
                x++;
        }

        printf("%d\n", x); // static_cast
    }

    return 0;
}
