try:
    a = int(input("enter value a :"))
    b = int(input("enter value b :"))
    result=a/b
    print(result)
except ZeroDivisionError:
    print("divide by zero error")
else:
    print(result)
finally:
    print("code executed successfully")

