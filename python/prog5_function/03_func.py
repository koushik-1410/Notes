def multiply(x1,y1):
    return x1*y1
x,y=input("ENter two numbers or enter one string and one number").split()
num1_is_int=0
num2_is_int=0
if x.isdigit():
    x=int(x)
    num1_is_int=1
if y.isdigit():
    y=int(y)
    num2_is_int=1
if (num1_is_int or num2_is_int ):
    a=multiply(x,y)
else:
    print("Wrong Input!!")
print(f"The multiplication of {x} and {y} is {a}")
