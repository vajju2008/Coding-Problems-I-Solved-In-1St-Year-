import sys

def solve():
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        n, k = map(int, sys.stdin.readline().split())
        prices = list(map(int, sys.stdin.readline().split()))
        tastiness = list(map(int, sys.stdin.readline().split()))
        max_taste = 0
        # Check all pairs of items to passes all these test cases 
        for i in range(n):
            for j in range(i + 1, n):
                high = max(prices[i], prices[j])
                low = min(prices[i], prices[j])
                discount = min(high // 2, 100)
                total_cost = (high - discount) + low
                
                if total_cost <= k:
                    max_taste = max(max_taste, tastiness[i] + tastiness[j])
        print(max_taste)
if __name__ == "__main__":
    solve()
