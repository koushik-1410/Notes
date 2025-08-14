class Car:
    def __init__(self, brand):
        self.__brand = brand  # Private attribute

    # Getter using @property
    @property
    def brand(self):
        print("Getting brand...")
        return self.__brand

    # Setter using @brand.setter
    @brand.setter
    def brand(self, value):
        print("Setting brand...")
        if value.strip() != "":
            self.__brand = value
        else:
            print("Invalid brand name! Cannot be empty.")


def main():
    car = Car("Ford")
    print(car.brand)     # No need to call get_brand()
    car.brand = "Nissan" # No need to call set_brand()
    print(car.brand)
main()

# Another method

class Car:
    def __init__(self, brand, model):
        self.__brand = brand    # private attribute
        self.model = model      # public attribute

    # Getter for brand
    def get_brand(self):
        return self.__brand

    # Setter for brand
    def set_brand(self, new_brand):
        # We can add validation here
        if new_brand.strip() != "":
            self.__brand = new_brand
        else:
            print("Brand name cannot be empty!")

    # Another getter for model (optional)
    def get_model(self):
        return self.model

def main():
    my_car = Car("Toyota", "Corolla")

    # Using getter
    print("Brand:", my_car.get_brand())     # Output: Toyota

    # Using setter
    my_car.set_brand("Honda")
    print("Updated Brand:", my_car.get_brand())  # Output: Honda

    # Trying invalid brand
    my_car.set_brand("  ")  # Output: Brand name cannot be empty!
    print("Brand still:", my_car.get_brand())  # Output: Honda

main()





