
# UPESx162
# CSE / Python3 Programs
# primeOrNot (Sieve of Eratosthenes)
# Recommended execution on https://repl.it/languages/python3

def isPrime(n):
	if n<=1:
		print("{0} is not a Prime Number".format(n))
		return False
	listOfPrimes=[True for i in range(n+1)] 
	pos=2
	
	while( pos*pos<=n ):
		if( listOfPrimes[pos] ):
			for i in range(pos * pos, n+1, pos): 
				listOfPrimes[i] = False
		pos+=1

	if listOfPrimes[n] == True:
		print("{0} is a Prime Number.".format(n))
		return True
	else: 
		print("{0} is not a Prime Number.".format(n))
		return False


if __name__=='__main__':
	num=int(input("Enter Number: "))
	isPrime(num)	


# https://github.com/sarthakjain95
# Sarthak Jain