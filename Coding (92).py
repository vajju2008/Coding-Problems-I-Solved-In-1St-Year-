class Contact:
    def __init__(self, name, phone, email):
        self.name = name
        self.phone = phone
        self.email = email
    def update(self,phone=None,email=None):
        if phone:
            self.phone = phone
        if email:
            self.email = email
    def display(self):
        print(f"Name: {self.name},\n Phone: {self.phone},\n Email: {self.email}")

contacts ={}
def add(contact_obj):
    if contact_obj.name in contacts:
        print(f"Contact {contact_obj.name} already exists")
    else:
        contacts[contact_obj.name] = contact_obj
        print(f"New contact {contact_obj.name} created")
def List_contacts():
    if contacts:
        print("All contacts")
        for c in contacts.values():
            c.display()
    else:
        print("No contacts")
def search_contacts(name):
    if name in contacts:
        contacts[name].display()
        print(f"Contact {name} found")
    else:
        print(f"Contact {name} not found")
def update_contact(name,phone=None,email=None):
    if name in contacts:
        contacts[name].update(phone,email)
        print(f"Contact {name} updated")
    else:
        print(f"Contact {name} not found")
def remove_contact(name):
    if name in contacts:
        del contacts[name]
        print(f"Contact {name} removed successfully")
    else:
        print(f"Contact {name} not found")
while True:
    print("Contact information:")
    print("1. Add a new contact")
    print("2.  Remove a contact")
    print("3. Search  contacts")
    print("4. Update  contact")
    print("5. List all contacts")
    print("6. Exit")
    choice = input("Enter your choice: ")
    if choice == "1":
        name=input("Enter your name: ")
        phone=eval(input("Enter your phone: "))
        email=input("Enter your email: ")
        add(Contact(name,phone,email))
    elif choice == "2":
        List_contacts()
    elif choice == "3":
        search_contacts(input("Enter your name: "))
    elif choice == "4":
        name=input("Enter your name: ")
        phone=eval(input("Enter your phone: "))
        email=input("Enter your email: ")
        update_contact(name,phone,email)
    elif choice == "5":
        remove_contact(input("Enter your name: "))
    elif choice == "6":
        break
    else:
        print("Invalid choice")
