import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    
    out = []
    for _ in range(t):
        n = int(input_data[idx])
        idx += 1
        
        a = [int(x) for x in input_data[idx : idx+n]]
        idx += n
        
        min_temp = min(a)
        max_temp = max(a)
        
        moderate_days = sum(1 for temp in a if min_temp < temp < max_temp)
        out.append(str(moderate_days))
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()
