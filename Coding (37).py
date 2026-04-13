# cook your dish here
## The first line of input will contain a single integer  t no fof test cases 

import sys

def solve():
    # Read all input in a  input
    input_data = sys.stdin.read().split()
    if not input_data:
        return # retuen to it stae 
    
    T = int(input_data[0])
    out = []
    
    # Process each test cases in the code ss
    idx = 1
    for _ in range(T):
            
        N = int(input_data[idx])
        S = int(input_data[idx+1])
        idx += 2
        

        if S <= 5 * N:
            out.append(str(6 * N))
        else:
            out.append(str(11 * N - S))

    print('\n'.join(out))

if __name__ == '__main__':
    solve()