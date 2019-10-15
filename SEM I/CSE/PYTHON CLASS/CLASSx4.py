#! /usr/bin/env python3

# A dictionary is a collection which is unordered, changeable and indexed. 
# In Python dictionaries are written with curly brackets, and they have keys and values.

person= {
	"Name":"John Doe",
	"SAP ID": 50008799,
	"Course": "B. Tech. CSE"
}

print(person)

# You can access object's properties by using key names
print("Person's name is {}".format(person["Name"]))

# Change values using this statement:
person["Name"]= "Mary Doe"

# You can also use .values() function to retrieve all the values of a predefined object
print( person.values() )

# And .keys() function to get all the keys from a dictionary
print( person.keys() )

# Q. Print all values in the dictionary one-by-one
# Usual 
# for prop in person: print(person[prop])
# Using values function
# for vals in person.values(): print(vals)

print()

#  We can loop through both the keys and values by using the items function
for x,y in person.items(): print( "{1}\t for {0}".format(x,y) )

# To check if a key is present in the dictionary
if "Name" in person: print("\n\"Name\" is present in person ")

print("(Person) object's length is {}\n".format(len(person)))

# Add an item to the dictionary using a new index key
# (and) assigning a value to it

print("Adding Age ", end="")
person["Age"]= 32 
print(person)

# Use the pop method to remove a item with specified key-name from
# the dictionary

# Without key-name, it would just remove the last item
print("Removing Age ", end="")
person.pop("Age")
print(person)

# The 'del' keyword removes the item with the specified key-name from the dictionary
del person["Course"]
print(person)

# '.clear()' clears entire dictionary
person.clear()
print(person)

# 'del' can also delete entire dictionary
del person

try:
	print(person)
except:
	print("Person is not defined!")

# Redefining
person= {
	"Name":"John Doe",
	"SAP ID": 50008799,
	"Course": "B. Tech. CSE",
	"Age": 32
}

# We can also create copy of a dictionary by using copy function
person_nth= person.copy()
print(person_nth)


