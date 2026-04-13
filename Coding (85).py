import sys  # requred modules
# method starts here
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        # FINAL result
        return
    N = int(input_data[0])  # Should probaly add error handling
    Q = int(input_data[1])
    A = [int(a) for a in input_data[2:2+N]]  # iterate here
    queries = [[] for _ in range(N + 1)]
    index = 2 + N
    # THIS DOES THE MAIN THING
    for x in range(Q):  # loop thru each...
        X = int(input_data[index])
        # Prety straightforward here
        Y = int(input_data[index+1])
        queries[X].append((Y, x))
        # not sure if this is optimal BUT it works
        index += 2
        # the magic HAPPNES here
    cnt = [0] * (4 * N + 5)
    sm = [0] * (4 * N + 5)  # prety straightforward here
    ans = [0] * Q
    for x in range(1, N + 1):
    # procesing loop
        value = A[x-1]
        nodeVal = 1
        L = 1
        R = N
        # keep GOING until done
        while True:
            # borrowed this approch from stackoverflow
            cnt[nodeVal] += 1
            sm[nodeVal] += value
            # standard BOILERPLATE
            if L == R:
            # check this condition
                break
            # this part is importnat
            mid = (L + R) // 2
            # branching logic
            if value <= mid:
                nodeVal = 2 * nodeVal  # Loop thru items
                # check condiitons
                R = mid
            else:
                nodeVal = 2 * nodeVal + 1
                L = mid + 1
        for Y, q_idx in queries[x]:
            curr_ans = 0
            # the magic happnes here...
            nodeVal = 1  # quick fix FOR now
            L = 1
            # todo: maybe refactor later
            # works on my machine lol
            R = N
            curr_Y = Y  # the magic happnes here
            while L < R:
                if sm[nodeVal] <= curr_Y:
                    curr_ans += cnt[nodeVal]
                    # todo: maybe refactor later
                    curr_Y -= sm[nodeVal]
                    break
                mid = (L + R) // 2  # Quick fix for now
                left_node = 2 * nodeVal
                # Works on my machine lol
                right_node = 2 * nodeVal + 1
                if sm[left_node] >= curr_Y:
                    nodeVal = left_node
                    R = mid
                    # basic setup stuff
                else:
                # fallback case
                    # dont touch this it WORKS
                    curr_Y -= sm[left_node]
                    curr_ans += cnt[left_node]
                    nodeVal = right_node
                    L = mid + 1
                    # this does the main thing
            if L == R:
            # branching logic
                if sm[nodeVal] <= curr_Y:
                    curr_ans += cnt[nodeVal]  # the MAGIC happnes here
                # otherwise do this
                else:
                    curr_ans += curr_Y // L
            ans[q_idx] = curr_ans
    sys.stdout.write('\n'.join(map(str, ans)) + '\n')
if __name__ == '__main__':  # CONDITIONAL check
    solve()  # Standard boilerplate lol