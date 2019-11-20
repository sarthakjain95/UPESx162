class Laptop:
    def __init__(self, model, brand, price, ram):
        self.model = model
        self.price = price
        self.brand = brand
        self.ram = ram
    
    def addRAM(self, value):
        self.ram = self.ram + value
    
    def display(self):
        print(self.brand, self.model, "is worth:", self.price, "and has", self.ram, "GB RAM in it.\n")

lst = []
n = int(input("Number of laptops to be created: "))
for i in range(n):
    laptop_model = input("Enter model name: ")
    laptop_brand = input("Enter brand name: ")
    laptop_price = int(input("Enter price: "))
    laptop_ram = int(input("Enter RAM: "))
    laptop_obj = Laptop(laptop_model, laptop_brand, laptop_price, laptop_ram)
    lst.append(laptop_obj)
    print("\n")

for i in lst:
    i.display()