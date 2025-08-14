user_score=int(input("Enter the score"))
if user_score>100:
    print("Wrong grading")
elif user_score>=90:
    print("The grade id A")
elif user_score>=80:
    print("The grade is B")
elif user_score>=70:
    print("The grade is C") 
elif user_score>=60:
    print("The grade is D")
else:
    print("The grade id F")              