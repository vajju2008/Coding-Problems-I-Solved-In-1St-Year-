product_id=int(input("Enter the product id :"))
name=input("Enter product name :")
price=float(input("Enter product price :"))
quantity=int(input("Enter product quantity :"))
category=input("Enter product category :")
supplier=input("Enter product supplier :")
reorder_level=int(input("Enter reorder _level :"))
#-----Grocery Details------
expiry_date=input("Enter expiry date :")
#-----Electronic attributes-----
warranty=int(input("Enter warranty"))
#------Sales Attributes------
sale_id=int(input("Enter dale id :"))
quantity_sold=int(input("Enter quantity sold :"))
total_sale_amount=quantity_sold *price
sale_date=input("Enter sale date :")

#-------Display Details-------
print("\n-----Product Details-----")
print("Product Id:",product_id)
print("Product Name:",name)
print("Product Price:",price)
print("Product Quantity:",quantity)
print("Product Category:",category)
print("Product Supplier:",supplier)
print("Product Reorder Level:",reorder_level)
print("Product Expiry Date:",expiry_date)
print("Product Warranty:",warranty)
print("Product Sale Date:",sale_id)
print("Product Sale Amount:",total_sale_amount)
print("Product Sale Date:",sale_date)