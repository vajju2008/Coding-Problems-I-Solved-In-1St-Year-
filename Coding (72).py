import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    iterator = iter(data)
    
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    results = []
    
    for _ in range(num_test_cases):
        try:
            L = int(next(iterator))
            W = int(next(iterator))
            R = int(next(iterator))
            G = int(next(iterator))
            B = int(next(iterator))
        except StopIteration:
            break

        sides = [L, L, W, W]
        sides.sort(reverse=True)
        
        found_4 = False
        
        stack = [(0, R, G, B)]
        
        while stack:
            idx, r, g, b = stack.pop()
            
            if idx == 4:
                found_4 = True
                break
            
            current_side = sides[idx]
            
            if r >= current_side:
                stack.append((idx + 1, r - current_side, g, b))
            if g >= current_side:
                stack.append((idx + 1, r, g - current_side, b))
            if b >= current_side:
                stack.append((idx + 1, r, g, b - current_side))
                
        if found_4:
            results.append("4")
            continue
            
        found_5 = False
        
        subsets_of_3 = []
        for i in range(4):
            subset = sides[:i] + sides[i+1:]
            subsets_of_3.append(subset)
            
        for subset in subsets_of_3:
            stack_5 = [(0, R, G, B)]
            
            while stack_5:
                idx, r, g, b = stack_5.pop()
                
                if idx == 3:
                    rem_colors = 0
                    if r > 0: rem_colors += 1
                    if g > 0: rem_colors += 1
                    if b > 0: rem_colors += 1
                    
                    if rem_colors == 2:
                        found_5 = True
                        break
                    continue

                curr = subset[idx]
                
                if r >= curr:
                    stack_5.append((idx + 1, r - curr, g, b))
                if g >= curr:
                    stack_5.append((idx + 1, r, g - curr, b))
                if b >= curr:
                    stack_5.append((idx + 1, r, g, b - curr))
            
            if found_5:
                break
        
        if found_5:
            results.append("5")
        else:
            results.append("6")

    print('\n'.join(results))

if __name__ == '__main__':
    sys.setrecursionlimit(2000)
    solve()