T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    total = sum(A)
    if total % 2 == 0:
        print("YES")
    else:
        print("NO")
