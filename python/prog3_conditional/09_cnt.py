year=int(input("Enter a year"))
if (year%400==0) or (year%4==0 and year%100!=0):
    print("Your entered year is leapyear")
else:
    print("Your entered year is not leapyear")