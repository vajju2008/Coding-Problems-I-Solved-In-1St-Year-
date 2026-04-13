import csv
d=[
    {'ID':'111','NAME':'GANESH','BASIC':21000,'BONUS':10},
{'ID':'222','NAME':'RAMESH','BASIC':25000,'BONUS':8},
{'ID':'333','NAME':'BALAJI','BASIC':32000,'BONUS':6.8},
{'ID':'444','NAME':'RAJESH','BASIC':45000,'BONUS':7.5},]
lable=["ID","NAME","BASIC","BONUS"]
with open ("employee.csv",'w',newline='') as f:
    w=csv.DictWriter(f,fieldnames=lable)
    w.writeheader()
    w.writerows(d)















