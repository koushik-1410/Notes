user_age= int(input("Enter an age:"))
price=12 if user_age>=18 else 8
day_of_purchase=(input("Enter the date of purchase:")).upper()
if day_of_purchase=="WEDNESSDAY":
    price=price-2
    # price-=2 ctrl+/ make this comment
print("The price of the ticket is$",price)
