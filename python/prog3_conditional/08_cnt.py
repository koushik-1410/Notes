password=input("Enter your password")
len=len(password)
if(len>10):
    print("your password has ",len,"charecter and it is strong")
elif(len>6):
    print("your password has ",len,"charecter and it is medium")
else:
    print("your password has ",len,"charecter and it is weak")     