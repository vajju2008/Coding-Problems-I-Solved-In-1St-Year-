import sys

def solve():
    input = sys.stdin.read
    
    data = input().split()
    
    iterator = iter(data)
    
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    output = []

    for _ in range(num_test_cases):
        try:
            N = int(next(iterator))
            A = []
            for _ in range(N):
                A.append(int(next(iterator)))
        except StopIteration:
            break

        if N == 0:
            output.append("0")
            continue

        A.sort()
        M = A[-1] 

        candidates = []
        
        for i in range(N):
            val = A[i]
            
            while val < M:
                val *= 2
            
            candidates.append((val, i))
            candidates.append((val * 2, i))
            
            if val > A[i]:
                candidates.append((val // 2, i))

        candidates.sort(key=lambda x: x[0])

        min_diff = float('inf')
        count = 0
        freq = [0] * N
        left = 0
        
        num_candidates = len(candidates)
        
        for right in range(num_candidates):
            val_r, idx_r = candidates[right]
            
            if freq[idx_r] == 0:
                count += 1
            freq[idx_r] += 1
            
            while count == N:
                val_l, idx_l = candidates[left]
                
                current_diff = val_r - val_l
                if current_diff < min_diff:
                    min_diff = current_diff
                
                freq[idx_l] -= 1
                if freq[idx_l] == 0:
                    count -= 1
                left += 1
                
        output.append(str(min_diff))

    print('\n'.join(output))

if __name__ == '__main__':
    solve()