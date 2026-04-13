try:
        a=int(input("enter first number"))
        b=int(input("enter second number"))
        c=a/b
except ZeroDivisionError:
        print("division by zero")
else:
        print(c)
finally:
        print("code executed successfully")
