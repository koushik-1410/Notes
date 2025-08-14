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
            # def fullname(self):
            #     return f"EV>>{self.brand}--{self.model}"
            # you have the acces of the full name defined in Car no need to write this here
            
                   

def main():
       my_car1=Car("mahindra","Xuv700")
       my_elccar=ElectricCar("Tata","Punch","500Kw")
       print(f"Details of my first car:\n{my_car1.fullname()}")
       print(f"Details of my second car::\n{my_elccar.fullname()}")

main()

