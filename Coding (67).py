def linearSearch(array,n,x):
    for i in range(0,n):
        if (array[i]==x):

            return i

    return -1


array = list(map(int,input("Enter the elements of the array seperated bye space:").split()))
x = int(input("Enter the element for search for:"))

n = len(array)
result = linearSearch(array,n,x)
if result != -1:
    print(f"element{x} found at index{result}")
else:
    print("Element{x} not found in the array")
