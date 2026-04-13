import sys

def solve():
    # Reading all input at once to handle multiple test cases efficiently
    input = sys.stdin.read
    data = input().split()
    
    iterator = iter(data)
    
    try:
        # Get number of test cases
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    results = []
    
    for _ in range(num_test_cases):
        try:
            N = int(next(iterator))
            A = int(next(iterator))
            B = int(next(iterator))
            
            temps = []
            for _ in range(N):
                temps.append(int(next(iterator)))
            
            wear_count = 0
            has_jacket = False  # Chef starts without a jacket
            
            for temp in temps:
                if has_jacket:
                    # We only remove the jacket if it's strictly hotter than B
                    if temp > B:
                        has_jacket = False
                else:
                    # We only put on the jacket if it's strictly colder than A
                    if temp < A:
                        has_jacket = True
                        wear_count += 1
            
            results.append(str(wear_count))
            
        except StopIteration:
            break
            
    # Print all results separated by newlines
    print('\n'.join(results))

if __name__ == '__main__':
    solve()