# cook your dish here
#The first line of input will contain a single integer only contains  t
#The first line containsz 2 integers 
#second n intergrs means infinite 
# third binary means infinite 
def solve():
    T = int(input())
    for _ in range(T):
            
            
        N, K = map(int, input().split())
        
        A = list(map(int, input().split())) # reads the remaining setas in the sports 
        S = input().strip()
        
        available_costs = []
        for i in range(N):
                
            if S[i] == '0':
                available_costs.append(A[i])
                
        if len(available_costs) < K:
            print("-1")
        else:
            available_costs.sort() # sorts thre greegily pick or leats
            print(sum(available_costs[:K]))

if __name__ == "__main__":
    solve()