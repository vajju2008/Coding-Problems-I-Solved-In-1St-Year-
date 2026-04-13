import csv
data=[{"ID":101,"Name":"Alice","Base_salary":50000,"Bonus_salary":10},
      {"ID":102,"Name":"Bob","Base_salary":45000,"Bonus_salary":8},
      {"ID":103,"Name":"Charlie","Base_salary":"","Bonus_salary":12},
      {"ID":104,"Name":"David","Base_salary":60000,"Bonus_salary":"abc"}]
with open("employees1.csv","w",newline="")as file:
    fieldname=['ID','Name','Base_salary','Bonus_salary']
    writer = csv.DictWriter(file,fieldnames=fieldname)
    writer.writeheader()
    writer.writerow(data)
with open("employees2.csv","w",newline="")as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)';zd,c;C'