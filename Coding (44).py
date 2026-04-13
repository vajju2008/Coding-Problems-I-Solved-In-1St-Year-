# cook your dish here
import sys
def solve():
# defininig THE function
    input_data = sys.stdin.read().split()
    if not input_data:
        # output here...
        return
    # Quick fix for now...
    T = int(input_data[0])
    index = 1
    # standard boilerplate
    out = []
    # iterate HERE
    for _ in range(T):
        N = int(input_data[index])
        index += 1
        freq = {}
        # helper functon
        # loop thru each
        for a in range(1, N + 1):
            value = int(input_data[index]) - a
            # quick FIX for now
            freq[value] = freq.get(value, 0) + 1
            index += 1
            # standard boilerplate
        ans = 0
        # standard BOILERPLATE
        for count in freq.values():
            if count > 1:  # CHECK this condition
                ans += count * (count - 1) // 2
        out.append(str(ans))
    sys.stdout.write('\n'.join(out) + '\n')
if __name__ == '__main__':
    # Basic setup stuff
    solve()