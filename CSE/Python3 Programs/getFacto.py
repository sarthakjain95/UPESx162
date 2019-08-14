
# UPESx162
# CSE / Python3 Programs
# getFactorial
# Recommended execution on https://repl.it/languages/python3

def getFactorial(n):
	n=int(n)
	if n==None:
		return -1
	retval=1
	for i in range(2,n+1):
		retval*=i
	return retval

if __name__=='__main__':
	lim=input( "Enter Number for factorial function: " )
	print("{0}! is {1}".format(lim,getFactorial(lim)))

# https://github.com/sarthakjain95
# Sarthak Jain