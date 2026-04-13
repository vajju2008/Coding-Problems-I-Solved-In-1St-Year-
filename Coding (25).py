import csv
with open("c.csv","w",newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["age", "name", "marks"])
    writer.writerow([3,"josh",8990])
    writer.writerow([6,"sravs",9000])
    writer.writerow([5,"joe",7809])
with open("c.csv","r") as f:
    reader = csv.reader(f)
    next(reader)
    for row in reader:
        if (int(row[2])>8000):
            row[]
            print(row)

