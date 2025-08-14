n=int(input("Enter a number:"))
sum_even =0
for num in range(1,n+1):
    if num%2==0:
        sum_even+=num
print("The sum of even number is=",sum_even)