n=int(input("Enter a number:"))

for num in range(1,11):
    if num==5:
        continue
    print(n,"x",num,"=",num*n)