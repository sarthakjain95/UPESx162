#! /usr/bin/env python3

import random,math,os,sys

a=33
b=20

if b>a:
	print("b is greater than a")

# Gives out indentation error
# if b>a:
# print("b is greater than a")

if b>a:
	print("b is greater than a")
else:
	print("a is probably greater than or equal to b")


if b>a:
	print("b is greater than a")
elif a>b:
	print("a is greater than b")
else:
	print("Both a and b are equal")

print("Changing variables as a=33 b=33")
a=33
b=33

if b>a:
	print("b is greater than a")
elif b==a:
	print("a and b are equal")

x=41

if x>10:
	print("Above 10")
	if x>20:
		print("Above 20")
	else:
		print("Below 20 or Equal to")
else:
	print("Below or equal to 10")

a=1
b=2

if a==1:
	if b==2:
		print("a is 1 and b is 2")

if a==1 and b==2: print("Again, a is 1 and b is 2")

