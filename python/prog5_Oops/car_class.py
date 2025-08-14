class Car:
    def __init__(self,brand,model):
        self.__brand=brand
        self.model=model
    def get_brand(self):
        return self.__brand+"!!!"
    
def main():
    new_car=Car("toyota","corola")    
if __name__=="__main__":
    main()