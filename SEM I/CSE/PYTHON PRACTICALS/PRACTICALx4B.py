# -*- coding: utf-8 -*-

# PRACTICAL 4B

# Q1) Find a factorial of given number.
def getFacto(num):
	facto= 1
	for i in range(1,num+1):
		facto*=i
	return facto

n= int( input("Enter a number for factorial:") )
print( "Factorial is", getFacto(n) )


# Q2) To find whether the given number is Armstrong number.
def isArmstrong(num):
	num_len= len( str(num) )
	digits_sum= 0
	for digit in list(str(num)):
		digits_sum+= int( digit ) ** num_len
	if num == digits_sum:
		return True
	else:
		return False

n= int( input("Enter a number to check for Armstrong Number:") )
if isArmstrong(n):
	print("It is an Armstrong Number.")
else:
	print("It is not an Armstrong Number.")


# Q3) Print Fibonacci series up to given term.
def getFibo(n):
	fibo= [0,1]
	while len(fibo) <= n:
		fibo.append( fibo[-1] + fibo[-2] )
	for num in fibo:
		print( num , end="\t" )
	print()

n= int( input("Enter the number of terms for Fibonacci Series:") )
getFibo(n)


# Q4) Write a program to find prime number.
def isPrime(x):
	lim= int(x**0.5)
	for i in range(2, lim+1):
		if x%i == 0:
			return False
	return True

n= int( input("Enter a number to check for Prime:") )
if isPrime(n):
	print("The given number is prime.")
else:
	print("The given number is not prime.")


# Q5) Check whether given number is palindrome or not.
def isPalindrome(n):
	n= str(n)
	for i in range( 0, len(n) ):
		if n[i] != n[ -1*i - 1 ]:
			return False
	return True

n= int( input("Enter a number to check for Palindrome:") )
if isPalindrome(n):
	print("The given number is a palindrome.")
else:
	print("The given number is not a palindrome.")


# Q6) Write a program to print sum of digits.
def sumOfDigits(num):
	num= list(str(num))
	sum_of_digits= 0
	for digit in num:
		sum_of_digits+= int(digit)
	return sum_of_digits

n= int( input("Enter a number for sum of digits:") )
print( "Sum of digits is",sumOfDigits(n) )


# Q7) Count and print all numbers divisible by 5 or 7 between 1 to 100.
counter= 0
for num in range(1,101):
	if num%5 == 0 or num%7 == 0:
		print(num, end=" ")
		counter+= 1

print( "\nIn 1 to 100, {} number(s) are divisible by 5 or 7.".format(counter) )


# Q8) All lower case to upper in string.
string= input("Enter a String:")
print("Upper case String is", string.upper())


# Q9) Print prime numbers between 1 and 100.
def isPrimeNumber(x):
	lim= int(x**0.5)
	for i in range(2, lim+1):
		if x%i == 0:
			return False
	return True

for num in range(2,100):
	if isPrimeNumber(num):
		print(num, end=" ")
print()

# Q10) Print the table for a given number: 
# 5 * 1 = 5
# 5 * 2 = 10

num= int( input("Enter a number to print table:") )
for i in range(1,11):
	print( " {} * {} = {} ".format(num, i, num*i) )

