# import 
import sys

# recursion limit
sys.setrecursionlimit(300000)

def main():
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return

    # precomputes limits
    MAXN = 200005
    MOD = 998244353

    # mobius func
    mu = [0] * MAXN
    mu[1] = 1
    primes = []
    noprime = [False] * MAXN

    for i in range(2, MAXN):
        if not noprime[i]:
            primes.append(i)
            mu[i] = -1
        for p in primes:
            if i * p >= MAXN:
                break
            noprime[i * p] = True
            if i % p == 0:
                mu[i * p] = 0
                break
            mu[i * p] = -mu[i]

    # divisors
    facs = [[] for _ in range(MAXN)]
    for i in range(1, MAXN):
        for j in range(i, MAXN, i):
            facs[j].append(i)

    iterator = iter(data)
    try:
        t_cases = int(next(iterator))
    except StopIteration:
        return

    out = []

    for _ in range(t_cases):
        M = int(next(iterator))
        
        # dp[i] expected value
        dp = [0] * (M + 1)
        # S[i] sum term
        S = [0] * (M + 1)
        
        for i in range(1, M + 1):
            if i == 1:
                dp[1] = 0
            else:
                # E[u] = 1 + sum(E[v] * cnt) / (M - floor(M/u))
                rem = M - (M // i)
                inv = pow(rem, MOD - 2, MOD)
                val = (S[i] * inv) % MOD
                dp[i] = (1 + val) % MOD
            
            lim = M // i
            if lim < 2:
                continue
                
            cur = dp[i]
            
            for k in range(2, lim + 1):
                nxt = i * k
                
                # count coprimes
                c = 0
                for d in facs[k]:
                    c += mu[d] * (lim // d)
                
                add = (cur * c) % MOD
                S[nxt] = (S[nxt] + add) % MOD

        ans = sum(dp) % MOD
        ans = (ans * pow(M, MOD - 2, MOD)) % MOD
        out.append(str(ans))

    print('\n'.join(out))

if __name__ == '__main__':
    main()