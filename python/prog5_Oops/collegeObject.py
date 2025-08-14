class College:
    def __init__(self,data):
        self.name=data["name"]
        self.no_of_prof=data["no_of_prof"]
        self.no_of_student=data["no_of_student"]
        self.details_of_cource=data["details_of_cource"]
        self.full_details_of_cource=data["full_details_of_cource"]

# college_data={"name":None,"no_of_prof":None,"no_of_student":None,"details_of_cource":None,"full_details_of_cource":None}
collegelist=[]
numofcource=None
num=int(input("Enter number of college::"))
for i in range(num):
    college_data={"name":None,"no_of_prof":None,"no_of_student":None,"details_of_cource":None,"full_details_of_cource":None}
    college_data["name"]=input(f"Enter the {i+1} college name:")
    college_data["no_of_prof"]=int(input("Enter the no of prof"))
    college_data["no_of_student"]=int(input("Enter number of student:"))
    numofcource=int(input("Number of cource"))
    college_data["details_of_cource"]=[]
    for i in range(numofcource):
        college_data["details_of_cource"].append(input(f"Enter the {i+1} cource:"))
    college_data["full_details_of_cource"]={}
    for i in range(numofcource):
        key=input("Name of the cource:")
        value=int(input(f"Number of the student in the cource{key}:"))
        college_data["full_details_of_cource"][key]=value
    collegelist.append(College(college_data))

for i in range(num):
    print(f"Details of the {i+1} college")
    print(f"Name of the college {collegelist[i].name}")
    print(f"Number of professor {collegelist[i].no_of_prof}")
    print(f"Number of student is {collegelist[i].no_of_student}")
    print("cources::")
    for y in range(numofcource):
        print(collegelist[i].details_of_cource[y],end=" ")
    print("Full details of cources")
    for keys,valus in collegelist[i].full_details_of_cource.items():
        print(f"{keys} has {valus} students")




