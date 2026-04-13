import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    iterator = iter(input_data)
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    results = []

    for _ in range(num_test_cases):
        try:
            N = int(next(iterator))
            A = next(iterator)
            B = next(iterator)
            C = next(iterator)
        except StopIteration:
            break

        K = 0
        S_start = 0
        N_inc = 0
        N_dec = 0

        for i in range(N):
            val = 0
            if B[i] == '1': val += 1
            if C[i] == '1': val -= 1
            
            K += val

            if A[i] == '0':
                S_start += val
                if val == -1:
                    N_inc += 1
                elif val == 1:
                    N_dec += 1
            else:
                if val == 1:
                    N_inc += 1
                elif val == -1:
                    N_dec += 1

        optimal_min = min(0, K)
        optimal_max = max(0, K)
        
        moves = 0
        current_S = S_start

        if S_start < optimal_min:
            needed = optimal_min - S_start
            performed_moves = min(needed, N_inc)
            moves += performed_moves
            current_S += performed_moves
            
        elif S_start > optimal_max:
            needed = S_start - optimal_max
            performed_moves = min(needed, N_dec)
            moves += performed_moves
            current_S -= performed_moves
        
        total_cost = moves + abs(current_S) + abs(K - current_S)
        results.append(str(total_cost))

    print('\n'.join(results))

if __name__ == '__main__':
    solve()