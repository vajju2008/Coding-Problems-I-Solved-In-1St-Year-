# cook your dish here
def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = input().strip()
        b = input().strip()
        
        if a == b:
            print(0)
            continue
            
        a_is_mixed = '0' in a and '1' in a
        b_is_mixed = '0' in b and '1' in b
        
        if a_is_mixed and b_is_mixed:
            print(0)
        else:
            print(1)

if __name__ == '__main__':
    solve()