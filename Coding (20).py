import sys

t = int(sys.stdin.readline().strip())
for _ in range(t):
    A, B, X, Y = map(int, sys.stdin.readline().split())
    trades = A // X
    result = A + B + trades * (Y - X)
    print(result)
