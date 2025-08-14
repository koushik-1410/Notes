"""
fruit="Banana"
colur=input("Enter the colour of the fruit").upper()
ripeness="Unripe"
if fruit=="Banana" and colur=="GREEN":
    ripeness="unripe"
elif fruit=="Banana" and colur=="YELLOW":
    ripeness="ripe"
elif fruit=="Banana" and colur=="BROWN":
    ripeness="overripe"    
else:
    print("ENter the colur properly")
    exit()
print("THe ripeness status of Banana is",ripeness)""
"""
# another code the above code is not efficient accordng to me
fruit="Banana"
colur=input("Enter the colour of the fruittt").upper()
ripeness="Unripe"
if fruit=="Banana":
        if colur=="GREEN":
            ripeness="unripe"
        elif colur=="YELLOW":
            ripeness="ripe"
        elif colur=="BROWN":
            ripeness="overripe"    
        else:
            print("ENter the colur properly")
            exit()
print("THe ripeness status of Banana is",ripeness)