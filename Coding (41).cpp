#include <stdio.h>

int main() {
    int T; // either x or 1 
    
    scanf("%d", &T);

    while (T--) {
        long long N, M;
        
        scanf("%lld %lld", &N, &M); // reads the n , m 

        if (M < N) {
                
            printf("NO\n");
            
        } else {
            long long diff = M - N;
            
            if (diff % 2 == 0 && diff <= 2 * N)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
