
# UPESx162
# CSE / Python3 Programs
# ArmstrongNumber
# Recommended execution on https://repl.it/languages/python3

def isArmstrongNumber(number):
	if number==None:
		return -1
	else:
		number=list(str(number))
		sum=0
		for digit in number:
			sum+= int(digit)**3
		if str(sum)==''.join(number):
			return True
		else:
			return False

if __name__=='__main__':
	while True:
		val=input("Input the number: ")
		try:
			val=int(val)
			if isArmstrongNumber(val):
				print("{0} is indeed an Armstrong Number".format(val))
			else:
				print("{0} is not an Armstrong Number".format(val))
			break
		except:
			print("Invalid Input! Retry.")
			continue

# https://github.com/sarthakjain95
# Sarthak Jain