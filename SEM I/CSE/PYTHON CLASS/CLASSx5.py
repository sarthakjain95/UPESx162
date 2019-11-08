
#! /usr/bin/env python3

def hello_world():
	print("Helllu!")

def customEnd(e, s="Hellu!"):
	print(s, end=e)

hello_world()
hello_world()

customEnd('')
customEnd('nope!\n')

# * => Spread operator for python3
def giveMeAnything(*args):
	print(args)

giveMeAnything(345,34,534,5,34,534,5)


data={}
# Class
def addDefaultCountry(country="India"):
	global data
	data["region"]= country 
	print(data)

addDefaultCountry("Russia")

def addToData(*content):
	global data
	if "unlistedDetails" not in data:
		data["unlistedDetails"]= []
	for con in content:
		data["unlistedDetails"].append(con)
	print(data)

addToData("John Doe", 43, "Street Artist")

def returns5():
	return 5

print(returns5())

print( "Here's your five: {}".format(returns5()) )

def breakDownNSA():
	pass

def facto(n):
	sum=1
	for i  in range(1,n+1):
		sum*=i

# Goes into infinite loop if correct condition is not given
def stackBasedFacto(n):
	# Really bad idea.
	# Has high space complexities for space for bigger numbers
	if n==1:
		return 1
	else:
		return n * stackBasedFacto(n-1)

for i in range(1, 3200):
	# f1= facto(i)
	# print( "facto for {} is {}".format(i, facto(i)) )
	f2=i
	try:
		f2= stackBasedFacto(i)
	except:
		print("Couldn't computer factorial from stackBasedFacto for {}".format(i))
		break
	# print( "stackBasedFacto for {} is {}".format(i,stackBasedFacto(i)) )

# Lambda functions are anonymous functions 
lam= lambda n: ( (n+1) & (n) )
for i in range(1,33):
	print("lam for {} is {}".format(i, lam(i)))


