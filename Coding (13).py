# cook your dish here
T = int(input().strip())
for _ in range(T):
    X, Y, Z = map(int, input().split())
    pairs_13 = min(X, Z)
    pairs_22 = Y // 2
    print(pairs_13 + pairs_22)
