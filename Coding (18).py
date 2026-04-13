# cook your dish here
def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = input().strip()
        b = input().strip()
        if a == b:
            print(0)
        elif len(set(a)) == 2 and len(set(b)) == 2:
            print(0)
        else:
            print(1)

if __name__ == '__main__':
    solve()