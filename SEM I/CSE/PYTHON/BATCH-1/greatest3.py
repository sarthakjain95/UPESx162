num1 = input("Enter number 1: ")
num2 = input("Enter number 2: ")
num3 = input("Enter number 3: ")

if num1>num2:
    if num1>num3:
        print("Number 1 is largest.")
    else:
        print("Number 3 is largest.")

else:
    if num2>num3:
        print("Number 2 is largest.")
    else:
        print("Number 3 is largest.")
