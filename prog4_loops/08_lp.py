"""
user_input=int(input("Enter a number:"))
copy=2
while copy<(user_input/2):
    if user_input%copy==0:
        print("The entered number is not prime::>>")
        exit()
    copy+=1    
print("The entered number is prime")
"""
user_input=int(input("Enter a number:"))
is_prime=0
if user_input==1:
    print("1 is nether prime nor non prime")
elif user_input==2:
    print("2 is a prime number")    
else:
    is_prime=1   
    for i in range(2,int((user_input)/2)):
        if (user_input%i)==0:
            is_prime=0
            print("The entered number is non prime")
            break
if is_prime==1:
    print("The entered number is prime")


       