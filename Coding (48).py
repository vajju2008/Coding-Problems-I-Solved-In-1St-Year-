import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    N = int(input_data[0])
    M = int(input_data[1])
    A = [int(x) for x in input_data[2:2+N]]
    low = 1
    high = max(A)
    ans = 0
    while low <= high:
        mid = (low + high) // 2
        
        people_sustained = sum(x // mid for x in A)
        
        if people_sustained >= M:
            ans = mid
            low = mid + 1
        else:
            high = mid - 1
            
    print(ans)

if __name__ == '__main__':
    solve()