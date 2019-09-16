# -*- coding: utf-8 -*-
import math

# Practical No 2
# Q1) 
#	Declare these variables (x, y and z) as integers. Assign a value of 9 to x,
#	Assign a value of 7 to y, perform addition, multiplication, division and subtraction 
#	on these two variables and Print out the result.
x=9
y=7
z=0
print("x+y=",x+y)
print("x-y=",x-y)
print("x*y=",x*y)
print("x/y=",x/y)

# Q2) 
#	Compute the area of a square having side(S) equal to 145 units. Assign the result 
#	to a variable named area and print it.
side=145
area=side**2
print("Area of Square is ",area,"units")

# Q3) 
#	Compute the area of a triangle having base 120 units (B) AND Height 33 units (H). 
#	Assign the result to a variable named area and print it.
base=120
height=33
print("Area of Triangle is",(0.5)*base*height)

# Q4) 
#	Write a Program where the radius of a circle is 12 units. Compute the area of a circle.
radius=12
print("Area of circle is",math.pi*(12**2))

# Q5)  
#	Write a Python program to solve (x+y)*(x+y)
#		Test data : x = 4 , y = 3
#		Expected output : (4+3)^2 = 49
x=4
y=3
print("(x+y)*(x+y) is",(x+y)*(x+y))

# Q6) 
#	Write a program to compute the length of the hypotenuse (c) of a right triangle 
#	having sides a = 133 , b = 72 units. Hint : remember the Pythagoras theorem.
p=72
b=133
print( "Hypotenuse is" , math.sqrt( p**2 + b**2 ) )

# Q7) 
#	The user enters two numbers. Store the numbers in two variables called input1 and 
#	input2. Swap the values of the two variables so that input1 has the value of input2 
#	and vice versa. Print out the two variables.
input1=int(input("Enter value 1:"))
input2=int(input("Enter value 2:"))
print("input1=",input1,'',"input2=",input2)
print("Swapping Values")
input1,input2=input2,input1
print("input1=",input1,'',"input2=",input2)

# Q8) 
#	Write a python program to get the least common multiple (LCM)  of two positive integers.


# Q9) 
#	Write a python program to compute the greatest common divisor  (GCD) of two positive integers.


# Q10) 
#	Write a program for printing following pattern by assigning a value 1 to a variable a: 
#	A)               1
#			1 2
#		       1 2 3
#	              1 2 3 4
#	B)              A
#                   A   A   A 
#               A   A   A    A   A
