t = int(input())
for _ in range(t):
    n = int(input())
    colors = list(map(int, input().split()))
    distinct_colors = len(set(colors))
    print(distinct_colors)
