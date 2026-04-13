# cook your dish here
# Iterate through the array $A$ from left to right in 
# Add 2 to your maximum length answer, clear your seen tracking (because subsequent pairs cannot overlap with this one ond continues the process for the remainder of the array
import sys # importing to system

def solve():
    input_data = sys.stdin.read().split() # it reads and splt the function 
    if not input_data: # if not data found it reutun to not 0 just starts from 1
        return
        
    T = int(input_data[0]) # array is 0 
    idx = 1
    out = []
    
    for _ in range(T):
            
        N = int(input_data[idx])
        idx += 1
        
        seen = set()
        max_len = 0
        
        for i in range(idx, idx + N):
            val = input_data[i]
            if val in seen: # if the give statement got true in if it leaves or contius es to else
                max_len += 2
                seen.clear()
            else:
                seen.add(val)
                
        out.append(str(max_len))
        idx += N
        
    print('\n'.join(out)) # all got correct it prints ina new line all the output

if __name__ == '__main__':
    solve()