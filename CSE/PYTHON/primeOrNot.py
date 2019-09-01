
# UPESx162
# CSE / Python3 Programs
# primeOrNot
# Recommended execution on https://repl.it/languages/python3

# Takes longer time to compute as the number gets bigger.

def isPrime(n):
	if n<=1:
		print("{0} is not a Prime Number".format(n))
		return False
	for i in range(2,n):
		if n%i is 0:
			print("{0} is not a Prime Number".format(n))
			return False
	print("{0} is a Prime Number".format(n))
	return True

if __name__=='__main__':
	num=int(input("Enter Number: "))
	isPrime(num)	

# https://github.com/sarthakjain95
# Sarthak Jain