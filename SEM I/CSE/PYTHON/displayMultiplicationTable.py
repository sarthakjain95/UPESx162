
# UPESx162
# CSE / Python3 Programs
# DisplayMultiplicationTable
# Recommended execution on https://repl.it/languages/python3

def displayTable(n):
	for i in range(1,11):
		print("{0} times {1} is {2}".format(n,i,n*i))

if __name__=='__main__':
	try:
		val=input("Enter number for table: ")
		val=int(val)
		displayTable(val)
	except:
		print("Invalid number. Try Again.")

# https://github.com/sarthakjain95
# Sarthak Jain