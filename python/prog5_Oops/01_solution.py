class Car:
    def __init__(self,userbrand,usermodel):
        self.brand=userbrand
        self.model=usermodel

# my_first_car=Car("Toyota","Corolla")
# print(my_first_car.brand)
numberOfcar=int(input("NEter number of car:"))
car_list=[]
for i in range(numberOfcar):
    brand=input(f"Enter the name of the brand of {i+1} car").upper()
    model=input(f"Enter hte name of thr brand of {i+1} car").upper()
    car_list.append(Car(brand,model))

print("Details of the my car")
for i in range(numberOfcar):
    print(f"{i+1} car::\nBrand:{car_list[i].brand}\nModel:{car_list[i].model}")