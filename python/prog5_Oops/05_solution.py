class Car:
    def __init__(self,brand,model):
        self.brand=brand
        self.model=model

    def fuel_type(self):
        return "Petrol or Disel"

class ElectricCar(Car):
    def __init__(self,brand,model,battery_size):
        super().__init__(brand,model)
        self.battery_size=battery_size
    
    def fuel_type(self):
        return "Electric Charge"


car_1=Car("Mahindra","Xuv700")
car_2=ElectricCar("Tata","Punch","800kwh")


print(car_1.fuel_type())
print(car_2.fuel_type())


