employees=[]
def add_employee():
    emp_id=input("Enter employee id:")
    name=input("Enter employee name:")
    salary=input("Enter employee salary:")
    employee={
        'id':emp_id,
        'name':name,
        'salary':salary
    }
    employees.append(employee)
    print("employee added successfully\n")
    def display_employees():
        if not employees:
            print("employee list empty\n")
        else:
            print("employee list:")
            for emp in employees:
                print("id:",emp['id'])
                print("name:",emp['name'])
                print("salary:",emp['salary'])
                def search_employee():
                    search_id=input("Enter employee id:")
                    for emp in employees:
                        if emp['id'] == search_id:
                            print("employee found")
                            print(emp)
                            return
                        print("employee not found")
                        while True:
                            print("1 Add employee")
                            print("2 Display employees")
                            print("3 search employee")
                            print("4 Exit")
                            choice=int(input("Enter your choice:"))
                            if choice==1:
                                add_employee()
                            elif choice==2:
                                display_employees()
                            elif choice==3:
                                search_employee()
                            elif choice==4:
                                print("Exiting program")
                                break
                            else:
                                print("Invalid choice")


