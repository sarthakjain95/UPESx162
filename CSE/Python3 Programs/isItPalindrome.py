
# UPESx162
# CSE / Python3 Programs
# palindromeNumber
# Recommended execution on https://repl.it/languages/python3

if __name__=='__main__':
	try:
		num=input("Enter a number/string to check for plaindrome: ")
		if num==num[::-1]:
			print("{0} is indeed a palindrome.".format(num))
		else:
			print("Apparently {0} is not a palindrome.".format(num))
	except:
		print("Error Occured. Retry.")

# https://github.com/sarthakjain95
# Sarthak Jain