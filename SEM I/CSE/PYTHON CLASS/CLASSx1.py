#! /usr/bin/env python3

import random,math,os,sys

# r_int = random.randint(2,45)
# print(r_int)

x=3
y=32
x+=y  # same as x = x+y
print("sum x,y \t",x)  

x=32
y=45
x-=y # same as x = x-y  ... -13 here
print("subtraction x,y\t",x)

x=32
y=9
x%=y
print("Remainder\t",x) # 5  27+5

x=32
y=9
x//=y
print("Floor Division\t",x) 

x=32
y=9
x**=y
print("Exponent\t",x)

x=31
y=29
x^=y
print("Result for XOR\t",x)

x=["this","one"]
y=["this","one"]
z=x

print("Is x y? \t", x is y)
print("x == y ?\t", x == y)

print("\"one\" in y\t","one" in y)

# Q convert to binary
# 60
# 13
# 16

print(bin(60))
print(bin(13))
print(bin(16))



