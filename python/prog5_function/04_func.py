import math
def circle(r):
    area= math.pi*r*r
    circumference = 2*math.pi*r
    return area,circumference
r=int(input("Enter the radius of the circle"))
x,y=circle(r)
print(f"The area for the circle is {round(x,2)},and the circumference is {round(y,2)}")
