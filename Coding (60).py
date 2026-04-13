def binarysearch (array,x,low,high):
    while low <= high:
        mid = low+(high-low)//2

        if array[mid]==x:
            return mid
        elif array[mid]<x:
            low = mid+1

        else:
            high =mid-1

    return-1

array = list(map(int,input("Enter the sorted array elements sepeerated by space:").split()))

x = int(input("enter the element to search for :"))

result = binarysearch(array,x,0,len(array)-1)

if result!= -1:
    print(f"Element{x}found a index{result}")

else:
    print(f"Element{x}not found in the array")
        
