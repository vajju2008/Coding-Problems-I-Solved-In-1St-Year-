# cook your dish here
# Read the input string
S = input().strip()

# Check if last three letters are "nta"
if S[-3:] == "nta":
    print("YES")
else:
    print("NO")
