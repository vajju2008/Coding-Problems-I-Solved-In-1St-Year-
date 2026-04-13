# cook your dish here
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
        N = int(next(iterator))
        A = next(iterator)
        B = next(iterator)
        C = next(iterator)
        
        arr0 = [0] * N
        arr1 = [0] * N
        arr_all = [0] * N
        
        for i in range(N):
            val = int(B[i]) - int(C[i])
            arr_all[i] = val
            
            if A[i] == '0':
                arr0[i] = val
            else:
                arr1[i] = val
        
        def get_abs_subarray_sum(arr):
            P = [0] * (N + 1)
            current = 0
            for i in range(N):
                current += arr[i]
                P[i+1] = current
            
            P.sort()
            
            total_diff = 0
            M = N + 1
            for i in range(M):
                coef = i - (M - 1 - i)
                total_diff += coef * P[i]
                
            return total_diff

        sum0 = get_abs_subarray_sum(arr0)
        sum1 = get_abs_subarray_sum(arr1)
        sum_all = get_abs_subarray_sum(arr_all)
        
        ans = (sum0 + sum1 + sum_all) // 2
        results.append(str(ans))

    print('\n'.join(results))

if __name__ == '__main__':
    solve()