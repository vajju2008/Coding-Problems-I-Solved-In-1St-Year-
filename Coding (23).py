# cook your dish here
import sys

input_data = sys.stdin.read().strip().split()
t = int(input_data[0])
idx = 1
out_lines = []
for _ in range(t):
    N = int(input_data[idx]); K = int(input_data[idx+1]); idx += 2
    A = list(map(int, input_data[idx:idx+N])); idx += N
    S = input_data[idx]; idx += 1

    available = [A[i] for i in range(N) if S[i] == '0']
    if len(available) < K:
        out_lines.append("-1")
    else:
        available.sort()
        out_lines.append(str(sum(available[:K])))

print("\n".join(out_lines))
