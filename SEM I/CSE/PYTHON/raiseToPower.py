
# UPESx162
# CSE / Python3 Programs
# raiseNumberToPower
# Recommended execution on https://repl.it/languages/python3

if __name__=='__main__':
	try:
		num=input("Enter the number to be raised: ")
		num=int(num)
		pwr=input("Enter the power of the number: ")
		pwr=int(pwr)
		print("{0} raised to the power {1} is {2}".format(num, pwr, num**pwr))
	except:
		print("Error Occured. The thing you typed in was probably not a number.")

# https://github.com/sarthakjain95
# Sarthak Jain