#include <stdio.h>

int main() {
    int T; // ip
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);
        
        int fastestCar = 1;
        int maxSpeed = -1;
        
        for (int i = 1; i <= N; i++) {
            int d, t;
            scanf("%d %d", &d, &t); // gurating that to bee multiple of t divdision 
            
            int speed = d / t;  // since d is multiple of t, this is always integer
            
            if (speed > maxSpeed) {
                maxSpeed = speed;
                fastestCar = i;  //fastnsurious car speed may be matched 
            }
            // If speed equals maxSpeed, keep the smaller label (already ensured by order)
        }
        
        printf("%d\n", fastestCar);
    }
    
    return 0;
}
