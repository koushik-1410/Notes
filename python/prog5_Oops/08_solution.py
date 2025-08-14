class Car:
    def __init__(self,userbrand,usermodel):
        self.__brand=userbrand
        self.__model=usermodel
    @property
    def brand(self):   #name is fixed you havr give this name to show error when user try to overwrite the brand
        return self.__brand
    @property
    def model(self):   #name is fixed you have give this name to show error when user try to overwrite the brand
        return self.__model # [**Note**]now you can not change the value of model,it is read only


def main ():
    car_1=Car("Toyota","Corola")
    # car_1.brand="Tata"
# If @property is not used, doing car_1.brand = "Tata" will create a new public attribute
# 'brand' on the object, which does NOT modify the internal __brand variable.
# This can cause confusion because it appears as if brand was changed.

# By using @property with the same name (brand), we make the attribute read-only
# and prevent accidental overwriting of the internal __brand.

# If you use @property but return self.model (instead of self.__model),
# you'll get a RecursionError because the method keeps calling itself.

    # car_1.model="Fortuner"    #same for model like brand
    print(car_1.brand)
    print(car_1.model)
    # print()
main()

