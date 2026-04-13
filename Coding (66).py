# cook your dish here
def solve():
    import sys # systems 
    
    input = sys.stdin.read
    data = input().split()
    
    iterator = iter(data)
    
    try:
        num_test_cases = int(next(iterator))
        
        for _ in range(num_test_cases):
            N = int(next(iterator))
            M = int(next(iterator))
            
            A = []
            for _ in range(N):
                A.append(int(next(iterator)))
                
            B = []
            for _ in range(M):
                B.append(int(next(iterator)))
            
            valid_cakes = 0
            for layer1_size in A:
                for layer2_size in B:
                    if layer2_size < layer1_size:
                        valid_cakes += 1
            
            print(valid_cakes)
            
    except StopIteration:
        pass

if __name__ == "__main__":
    solve()