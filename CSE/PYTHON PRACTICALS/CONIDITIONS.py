# -*- coding: utf-8 -*-

# CODE 1:
a = 33
b = 200
if b > a:
	print("b is greater than a")

# INDENTATION ERROR
#a = 33
#b = 200
#if b > a:
#print("b is greater than a")


# CODE 2:
a = 200
b = 33
if b > a:
	print("b is greater than a")
else:
	print("b is not greater than a")


# CODE 3:
a = 33
b = 33
if b > a:
	print("b is greater than a")
elif a == b:
	print("a and b are equal")


# CODE 4:
a = 200
b = 33
if b > a:
	print("b is greater than a")
elif a == b:
	print("a and b are equal")
else:
	print("a is greater than b")


# CODE 5:
x = 41

if x > 10:
	print("Above ten,")
	if x > 20:
		print("and also above 20!")
	else:
		print("but not above 20.")


# CODE 6:
a=1
b=2
if a==1:
	if b==2:
		print("a is 1 and b is 2")


# CODE 7:
a = 200
b = 33
if a > b: print("a is greater than b")


# CODE 8:
a = 2
b = 330
print("A") if a > b else print("B")


# CODE 9:
a = 330
b = 330
print("A") if a > b else print("=") if a == b else print("B")


# CODE 10:
a = 200
b = 33
c = 500
if a > b and c > a:
	print("Both conditions are True")


# CODE 11:
a = 200
b = 33
c = 500
if a > b or a > c:
	print("At least one of the conditions is True")

