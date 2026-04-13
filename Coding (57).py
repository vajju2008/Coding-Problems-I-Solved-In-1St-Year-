try:
    l=[10,20,30,40,50]
    index=int(input("enter index:"))
    print(l[index])
except IndexError:
    print("Index out of range")