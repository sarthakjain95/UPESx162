
# UPESx162
# CSE / Python3 Programs
# evenOrOdd
# Recommended execution on https://repl.it/languages/python3

if __name__=='__main__':
	while True:
		num=input("Input the number : ")
		try:
			num=int(num)
			if num%2==0:
				print("{0} is even".format(num))
			else:
				print("{0} is odd".format(num))
			break		
		except:
			print("Invalid Number!! Retry..")
			continue

# https://github.com/sarthakjain95
# Sarthak Jain