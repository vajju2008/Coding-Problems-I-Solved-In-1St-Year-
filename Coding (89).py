import sys

def is_imperfect(x):
    return (x % 2 == 0) ^ (x % 5 == 0)

def main():
    input_data = sys.stdin.read().split()
    T = int(input_data[0])
    nums = list(map(int, input_data[1:]))
    
    results = []
    for N in nums:
        if is_imperfect(N):
            results.append("0")
        else:
            diff = 1
            while True:
                if N - diff > 0 and is_imperfect(N - diff):
                    results.append(str(diff))
                    break
                if is_imperfect(N + diff):
                    results.append(str(diff))
                    break
                diff += 1
    print("\n".join(results))

if __name__ == "__main__":
    main()
