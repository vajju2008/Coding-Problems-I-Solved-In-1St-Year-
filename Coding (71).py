import sys
from collections import deque

def has_odd_digit(n):
    # Check if the number contains any odd digit
    s = str(n)
    for char in s:
        if int(char) % 2 != 0:
            return True
    return False

def get_digits(n):
    # Helper to get unique digits of n
    digits = set()
    temp = n
    while temp > 0:
        digits.add(temp % 10)
        temp //= 10
    # If n is 0 (though constraints say N>=1, intermediate can be 0)
    if n == 0:
        digits.add(0)
    return digits

def solve():
    try:
        input_data = sys.stdin.read().split()
    except Exception:
        return

    if not input_data:
        return

    iterator = iter(input_data)
    num_test_cases = int(next(iterator))

    for _ in range(num_test_cases):
        n_str = next(iterator)
        n = int(n_str)

        # Case 1: Already Odd
        if n % 2 != 0:
            print(0)
            continue

        # Case 2: Even but has an odd digit
        if has_odd_digit(n):
            print(1)
            continue
        
        # Case 3: All digits are even
        # Small impossible cases
        if n < 10:
            print(-1)
            continue

        # BFS to find the nearest number with an odd digit
        # Queue stores (current_number, steps_taken)
        queue = deque([(n, 0)])
        visited = {n}
        found = False
        
        while queue:
            curr, steps = queue.popleft()
            
            # Optimization: If steps are already high (empirically > 5), stop.
            # However, logic dictates we find it in max 2-3 steps.
            
            # Get digits to subtract
            # Since we know N originally had only even digits,
            # and we only subtract even digits, curr will always have even digits
            # UNTIL we find the target.
            
            # We can compute digits manually or string convert
            # String conversion is safe given constraints and small depth
            curr_s = str(curr)
            digits = set(int(d) for d in curr_s)
            
            for d in digits:
                next_val = curr - d
                
                if next_val not in visited and next_val >= 0:
                    # Check if next_val has an odd digit
                    # This is our target condition
                    if has_odd_digit(next_val):
                        # We found a number with an odd digit!
                        # Total cost = steps to get here + 1 (transition) + 1 (final subtraction)
                        print(steps + 1 + 1)
                        found = True
                        break
                    
                    visited.add(next_val)
                    queue.append((next_val, steps + 1))
            
            if found:
                break
        
        if not found:
            print(-1)

if __name__ == '__main__':
    solve()