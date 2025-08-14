class Car:
    def __init__(self,userbrand,usermodel):
        self.brand=userbrand
        self.model=usermodel



class Battery:
    def battery_info(self):
        return "THis is a battery info"
        
class Engine:
    def engine_info(self):
        return "THis is engine info"


class Electriccar(Car,Battery,Engine):
    pass


my_car=Electriccar("tata","punch")

print(my_car.battery_info())
print(my_car.engine_info())