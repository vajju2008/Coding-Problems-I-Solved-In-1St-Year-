# cook your dish here
import sys

t = int(sys.stdin.readline().strip())
for _ in range(t):
    N, S = map(int, sys.stdin.readline().split())
    if S <= 5 * N:
        print(6 * N)
    else:
        print(11 * N - S)
