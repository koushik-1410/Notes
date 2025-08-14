def sum_all(*args):
    return sum(args)
list=[]
x=int(input("Enter how many number do you eant to enter"))
for _ in range(x):
    y=int(input())
    list.append(y)
print(sum_all(*list))