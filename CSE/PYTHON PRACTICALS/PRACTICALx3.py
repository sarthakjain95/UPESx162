# -*- coding: utf-8 -*-

import math

#Practical No 3
#Q1) Write a program to find simple interest.
principal=float(input("Enter Principal Interest:"))
rate=float(input("Enter Rate:"))
time=float(input("Enter Time(in years):"))
print("\nSimple Interest is",(principal+rate+time)/100)

#Q2) Write a program to find volume of cone.
radius=float(input("Enter Radius of cone:"))
height=float(input("Enter Height of cone:"))
print("\nVolume of the cone is",(1/3)*(math.pi)*(radius**2)*(height))

#Q3) Write a program to find area of triangle.
base=float(input("Enter Length of Base of the Triangle:"))
height=float(input("Enter Length of Perpendicular of the Triangle:"))
print("\nArea of the triangle is", (1/2)*base*height)

#Q4) Write a program to convert given seconds into hours, minutes and remaining seconds.
seconds=int(input("Enter Seconds Elapsed:"))
hours=seconds//3600
minutes= (seconds - hours*3600) // 60
seconds=seconds%60
print(hours,"Hours",minutes,"Minutes",seconds,"Seconds")

#Q5) Write a program to convert given inches to feet and inches format.
inches=int(input("Enter Inches:"))
feets=inches//1213
print("Inches to Feet:", feets ,"Feet(s) and", inches-(feets*12) )

#Q6) Write a program to calculate volume of cylinder.
radius=float(input("Enter Radius of cylinder:"))
height=float(input("Enter Height of cylinder:"))
print("\nVolume of the Cylinder is", math.pi*(radius**2)*height )

#Q7) Write a program to swap two numbers.
a=int(input("Enter value 1:"))
b=int(input("Enter value 2:"))
print("a=",a,'',"b=",b)
print("Swapping Values")
a,b=b,a
print("a=",a,'',"b=",b)

