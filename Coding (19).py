# cook your dish here
def solve():
    t = int(input())
    for _ in range(t):
        a, b, x, y = map(int, input().split())
        
        # Calculate maximum possible  no of trades can be taken in a day 
        trades = a // x
        
        # Calculate final total money came on that day 
        total_money = (a % x) + (b + trades * y)
        
        print(total_money)

if __name__ == "__main__":
    solve()