class Car:
    def __init__(self,brand,model):
        self.__brand=brand
        self.model=model
    def get_brand(self):
        return self.__brand+"!!!"
    

def main():
    new_car=Car("Toyota","corola")

    # print(new_car.brand)    
    print(new_car.get_brand())
if __name__=="__main__":
    main()    