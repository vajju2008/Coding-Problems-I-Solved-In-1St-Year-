# cook your dish here
import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    N = int(input_data[0])
    Q = int(input_data[1])
    
    A = [int(x) for x in input_data[2:2+N]]
    
    queries = [[] for _ in range(N + 1)]
    idx = 2 + N
    for i in range(Q):
        X = int(input_data[idx])
        Y = int(input_data[idx+1])
        queries[X].append((Y, i))
        idx += 2
        
    cnt = [0] * (4 * N + 5)
    sm = [0] * (4 * N + 5)
    
    ans = [0] * Q
    
    for i in range(1, N + 1):
        val = A[i-1]
        
        node = 1
        L = 1
        R = N
        while True:
            cnt[node] += 1
            sm[node] += val
            if L == R:
                break
            mid = (L + R) // 2
            if val <= mid:
                node = 2 * node
                R = mid
            else:
                node = 2 * node + 1
                L = mid + 1
                
        for Y, q_idx in queries[i]:
            curr_ans = 0
            node = 1
            L = 1
            R = N
            
            curr_Y = Y
            while L < R:
                if sm[node] <= curr_Y:
                    curr_ans += cnt[node]
                    curr_Y -= sm[node]
                    break
                    
                mid = (L + R) // 2
                left_node = 2 * node
                right_node = 2 * node + 1
                
                if sm[left_node] >= curr_Y:
                    node = left_node
                    R = mid
                else:
                    curr_Y -= sm[left_node]
                    curr_ans += cnt[left_node]
                    node = right_node
                    L = mid + 1
                    
            if L == R:
                if sm[node] <= curr_Y:
                    curr_ans += cnt[node]
                else:
                    curr_ans += curr_Y // L
                    
            ans[q_idx] = curr_ans
            
    sys.stdout.write('\n'.join(map(str, ans)) + '\n')

if __name__ == '__main__':
    solve()