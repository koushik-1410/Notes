class Car:
    def __init__(self,brand,model):
        self.brand=brand
        self.model=model

    def fullname(self):
        return f"{self.brand}--{self.model}"
    
Car_list=[]
def main():
    num=int(input("Enter number of car:"))
    for i in range(num):
        brand=input(f"Enter the brand of the {i+1} car:")
        model=input(f"enter the model of the {i+1} car:")
        Car_list.append(Car(brand,model))
    #display 
    for i in range(num):
        print(f"Details of the {i+1} car::")
        print(Car_list[i].fullname())

main()        