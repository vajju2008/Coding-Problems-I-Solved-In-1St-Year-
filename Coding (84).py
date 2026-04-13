T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    total_wins = sum(A)
    min_diff = min(A[i] - B[i] for i in range(N))
    
    print(total_wins - min_diff)
