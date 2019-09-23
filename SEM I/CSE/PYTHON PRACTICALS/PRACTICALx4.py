# -*- coding: utf-8 -*-

# PRACTICAL 4

#1. Check whether given number is divisible by 3 and 5 both.
num= int(input("Enter a number:"))
if num%3==0 and num%5==0:
	print("Number is divisible by 3 and 5")

#2. Check whether a given number is multiple of five or not.
num= int(input("Enter a number:"))
if num%5==0:
	print("Number is a multiple of 5")

#3. Write a Python program to display sum of two given integers. If the sum is between 10 and 20 than display 15.
num1= int(input("Enter a number 1:"))
num2= int(input("Enter a number 2:"))
sumOfNumbers= num1+num2
if 10 < sumOfNumbers < 20:
	print("Sum of the given numbers is:",sumOfNumbers)

#4. Find the greatest among two numbers. If numbers are equal than print “numbers are equal”.
a= int(input("Enter a number 1:"))
b= int(input("Enter a number 2:"))
if a>b:
	print("a is greater than b")
elif b>a:
	print("b is greater than a")
else:
	print("Both given numbers are equal")

#5. Check whether voter is eligible for voting or not (eligible age >=18)
age= int(input("Enter your age:"))
if age>=18:
	print("Eligible for voting")

#6. Find the greatest among three numbers assuming no two values are same.
a= int(input("Enter a number 1:"))
b= int(input("Enter a number 2:"))
c= int(input("Enter a number 3:"))
if a>b:
	if a>c:
		print("a is the biggest input")
	else:
		print("c is the biggest input")
elif b>a:
	if b>c:
		print("b is the biggest input")
	else:
		print("c is the biggest input")
elif a==b and b==c:
	print("All the numbers are equal")
	

#7. Check whether the quadratic equation has real roots or imaginary roots. Display the roots.
#Lx**2 + Mx + N
l= int(input("Enter L (x^2 coefficient):"))
m= int(input("Enter M (x coefficient):"))
n= int(input("Enter N (constant):"))
print("Imaginary roots") if (m**2 - 4*l*n) < 0 else print("Real roots")

#8. Find whether a given year is a leap year or not.
year= int(input("Enter the year:"))
if year%400 == 0:
	print("Leap Year")
elif year%4 == 0 and year%100 != 0:
	print("Leap Year")
else:
	print("Not a Leap Year")

#9. Write a program which takes any date as input and display next date of the calendar
#e.g.
#I/P: day=20 month=9 year=2005
#O/P: day=21 month=9 year 2005


#10. Print the grade sheet of a student for the given range of cgpa. Scan marks of five subjects and calculate the percentage.
#CGPA=percentage/10
#CGPA range:
#0 to 3.4 -> F
#3.5 to 5.0->C+
#5.1 to 6->B
#6.1 to 7-> B+
#7.1 to 8-> A
#8.1 to 9->A+
#9.1 to 10-> O (Outstanding)
 
#Sample Gradesheet
#Name: Rohit Sharma
#Roll Number: R17234512 SAPID: 50005673
#Sem: /1 Course: B.Tech. CSE AI&ML
 
#Subject name: Marks
#PDS: 70
#Python: 80
#Chemistry: 90
#English: 60
#Physics: 50
#Percentage: 70%
#CGPA:7.0
#Grade: A


