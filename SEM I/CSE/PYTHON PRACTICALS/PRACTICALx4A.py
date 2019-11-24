# -*- coding: utf-8 -*-

# PRACTICAL 4A

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
def isLeap(year):
	if year%400==0:
		return True
	elif year%100==0:
		return False
	elif year%4==0:
		return True
	else:
		return False

day= int(input("Enter day:"))
month= int(input("Enter month:"))
year= int(input("Enter year:"))
if month==2:
	if isLeap(year):
		if day==29:
			day= 1
			month+=1
		else:
			day+=1
	else:
		if day==28:
			day= 1
			month+=1
		else:
			day+=1
elif month%2==0:
	if day==30:
		day= 1
		if month+1 > 12:
			year+=1
			month= 1
		else:
			month+=1
	else:
		day+=1
else:
	if day==31:
		day= 1
		month+=1
	else:
		day+=1
print("day=",day," month=",month," year=",year)

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
#Sem: 1 Course: B.Tech. CSE AI&ML
 
#Subject name: Marks
#PDS: 70
#Python: 80
#Chemistry: 90
#English: 60
#Physics: 50
#Percentage: 70%
#CGPA:7.0
#Grade: A

name= input("Enter Student name:")
roll= input("Enter Student Roll no.:")
sap= input("Enter Student SAP ID:")
sem= input("Enter Student Semester:")
course= input("Enter Student course:")

pds= int(input("Enter PDS marks:"))
py= int(input("Enter Python marks:"))
chem= int(input("Enter Chemistry marks:"))
eng= int(input("Enter English marks:"))
phy= int(input("Enter Physics marks:"))

total= pds+py+chem+eng+phy
percentage= total/5
cgpa= percentage/10
grade='A'

if 0 <= cgpa <= 3.4: grade= 'F'
elif 3.5 <= cgpa <= 5: grade= 'C+'
elif 5.1 <= cgpa <= 6: grade= 'B'
elif 6.1 <= cgpa <= 7: grade= 'B+'
elif 7.1 <= cgpa <= 8: grade= 'A'
elif 8.1 <= cgpa <= 9: grade= 'A+'
elif 9.1 <= cgpa <= 10: grade= 'O'

print("Name:",name)
print("Roll Number:",roll, " SAPID:",sap)
print("SEM:", sem, " COURSE:", course)

print("Subject Name : Marks")
print("PDS:",pds)
print("Python:",py)
print("Chemistry:",chem)
print("English:",eng)
print("Physics:",phy)

print("Percentage:",percentage)
print("CGPA:",cgpa)
print("Grade:",grade)

#Extra Questions

# Accept a number from user and determine if the nuber is divisibly by 7 and is a multiple of 5
num= int(input("Enter a number: "))
if num%7==0 and num%5==0:
	print("Number is divisible by 7 and is a multiple of 5")


# Accept a number from user and check if the number lies between 1 ans 20
num= int(input("Enter a number: "))
if 1<num<20:
	print("Number lies between 1 and 20")


# Accept temperature from user and convert that from
# 1. celcius to farhenheit
# 2. farhenheit to celcius
cel= int(input("Enter temperature in celcius: "))
print("Temperature in farhenheit:",  (cel*9/5)+32 )

far= int(input("Enter temperature in farhenheit: "))
print("Temperature in celcius:", (far-32)*(5/9) )
