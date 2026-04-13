import sys

def solve():
    # Reading input efficiently
    input = sys.stdin.read
    data = input().split()
    
    iterator = iter(data)
    try:
        T = int(next(iterator))
    except StopIteration:
        return

    results = []
    
    for _ in range(T):
        try:
            N = int(next(iterator))
            S = next(iterator)
        except StopIteration:
            break
        
        # Count character frequencies
        counts = {}
        possible = True
        
        for char in S:
            counts[char] = counts.get(char, 0) + 1
            # Optimization: As soon as we find a count > 2, we can stop
            if counts[char] > 2:
                possible = False
                break
        
        if possible:
            results.append("YES")
        else:
            results.append("NO")
            
    # Print all results
    print('\n'.join(results))

if __name__ == '__main__':
    solve()