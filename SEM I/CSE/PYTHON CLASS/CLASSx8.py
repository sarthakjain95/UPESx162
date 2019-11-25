# -*- coding: utf-8 -*-
#! /usr/bin/env python3

# Classes and Objects
# Suppose there is a class 'Vehicles'
# A few of the other objects can be represented as objects/children of this super class
# For instance, Car, Scooter, Truck are all vehicles and can be denoted as a derivative 
# of the class 'Vehicle'

# Furthermore, these derived objects can have some other properties that are unique  to 
# them and are not available in the super class.

# Superclass - Baseclass
# 'Subclasses' derive properties from the super class


class MeClass:
	print("\nIn Class")
	x=32
	
foo= MeClass()
print(foo)
print(foo.x)


class FirstClass:
	print("Inside Class")
	def __init__(self, prop):
		print("Inside Init function")
		self.x= prop
	
foo= FirstClass(45)
print(foo)
print(foo.x,'\n')


class Person:
	# Assignment of values to the properties of the objects created is done
	# inside the init function.
	def __init__(self, name, age, city):
		self.name= name
		self.age= age
		self.city= city

	def introduceInSpanish(self):
		print("Hola! Me llamo "+self.name)
	

# Treating Ramesh as an object.
ramesh= Person("Ramesh", 32, "Noida")
print( "Name:", ramesh.name )
print( "Age: ", ramesh.age )
print( "City:", ramesh.city )
ramesh.introduceInSpanish()


# To reassign/modify any propert of an object
# Object.Property= NewValue
ramesh.age= 55
print( "\nNew Age: ", ramesh.age )


# Let's delete his name from records.
del ramesh.name
# Gives out error. No attribute 'name'
# print( ramesh.name )
print( ramesh.__dict__ )


print("\nYou know what? I don't really like ramesh.")
print("Let's delete him.")
del ramesh
print("Deleted.")
try:
	print("Trying to access ramesh ...")
	print( ramesh.__dict__ )
except:
	print("There was an error. There's no ramesh.")
