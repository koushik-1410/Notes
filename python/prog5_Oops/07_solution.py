class Car:
    count=0
    def __init__(self,brand,model):
        Car.count+=1
        self.brand=brand
        self.model=model
    # def car_count():
    #     return Car.count

    @staticmethod
    def general_description():
        return "Car are mean of transport"

class ElectricCar(Car):
    def __init__(self,brand,model,battery_size):
        super().__init__(brand,model)
        self.battery_size=battery_size

car_1=Car("Mahindra","Xuv700")
car_2=ElectricCar("Tata","Punch","800kwh")


print(Car.count)
print(Car.general_description())
print(ElectricCar.general_description())
print(car_1.general_description())
