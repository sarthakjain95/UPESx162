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

laptop1 = Laptop("Ideapad", "Lenovo", 45000, 4)
laptop1.display()

print("Laptop after upgrading RAM: ")
laptop1.addRAM(4)
laptop1.display()

laptop2 = Laptop("Strix III", "ASUS ROG", 95000, 16)
laptop2.display()