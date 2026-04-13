import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0]) # no of test cases 
    results = []
    for i in range(1, 2 * T, 2):
        N = int(input_data[i])# first test cases
        Q = int(input_data[i+1])# Secondz test cases 
        segments = Q + 1 # no of segements i the 
        max_segment_size = (N + Q) // segments # segement sizzz
        min_error = max_segment_size // 2
        results.append(str(min_error))
    print('\n'.join(results))
if __name__ == '__main__':
    solve()