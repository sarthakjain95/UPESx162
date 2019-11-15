
# Default arguments: Arguments are set to some defaiult value
def customer(name, age=25): # age=25 means variable 'age' is set to 25 when not initialized
    print("Customer name is:", name, "and age is:", age)
customer("A")

# Variable length arguments:
# If function call consists more number of arguments than in function declaration , rest of all arguments are stored in tuples
# Minimum one argument is required. The variable length arguments should be the last argument in the function declaration.

def variable(name, *names):
    print("Argument 1: ", name)
    for i in range(len(names)):
        print("Values of exceeded arguments: ", names[i])

variable("S", "A", "R")