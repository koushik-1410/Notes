class Car:
    def __init__(self,userbrand,usermodel):
        self.brand=userbrand
        self.model=usermodel

    def fullname(self):
        return f"{self.brand}--{self.model}"


class ElectricCar(Car):
            def __init__(self,brand,model,battery_size):
                   super().__init__(brand,model)
                   self.battery_size=battery_size

my_car=ElectricCar("Tata","Punch","500kwh")

print(isinstance(my_car,ElectricCar))
print(isinstance(my_car,Car))        