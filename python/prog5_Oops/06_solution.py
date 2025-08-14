class Car:
    count=0
    def __init__(self,brand,model):
        Car.count+=1
        self.brand=brand
        self.model=model
    # def car_count():
    #     return Car.count

class ElectricCar(Car):
    def __init__(self,brand,model,battery_size):
        super().__init__(brand,model)
        self.battery_size=battery_size

car_1=Car("Mahindra","Xuv700")
car_2=ElectricCar("Tata","Punch","800kwh")



# print(Car.car_count())
print(Car.count())