
#! /usr/bin/env python3


def returnLambda(n):
	return lambda x: x*n

foo= returnLambda(32)

print(foo)
print(foo(32))

my_doubler= returnLambda(2)
my_tripler= returnLambda(3)

print( my_doubler("foo") + "bar" )
print( my_tripler("foo") + "bar" )

# Q.
# How does the control flow of python interpreter work in the above code?

# A.
# 'my_doubler' is assigned to a function that returns another function that is executed
#  with the value passed in the outer function.
#
# In layman's terms, the returnLambda function returns a function that is assigned to 'my_doubler'.
# The function that is assigned to my_doubler uses a variable that was given to 'returnLambda' function
# when it was called by my_doubler. (value '2')
# So my_doubler is basically lambda x:x*2



def changeList(l):
	l.append([324,23,4,324])
	print("\nValues inside changeList", l)

group= [3546,46,346]
changeList(group)
print("Values after function changeList", group)

def changeList2(l):
	l=[2343,4324]
	print("\nValues inside changeList2", l)

group= [32,43,4234]
changeList2(group)
print("After function changeList2",group,"\n")

# Q.
# What is the difference between the above two codes?
# Does python give the same result with immutable collections?

# A.
# 



import array as arr
# array( datatype, values )
ar= arr.array( 'd', [ 1.1, 324.3434534, 234234.234324 ] )
print(ar)
print("Length of your array is {}".format(len(ar)))

# Q.
# What is the datatype specifier used for character values in python3 array?

# A.
#

ar.append(546.4565)
print("After append",ar)
ar.extend( arr.array( 'd', [ 234234.234, 234234.234 ] ) )
print("After extension",ar)
ar.insert(2,46346.346346346)
print("After insertion",ar)
a= arr.array( 'd', [ 234234.234, 234234.234 ] )
b= arr.array( 'd', [ 2363646.45745, 346345345.3764645, 34643634.4 ] )
c= a+b
print(c)

print(c.pop(3))
c.remove(234234.234)
# print(c)

# Q.
# What is the difference between the pop function and the remove function in arrays?

print("\nc is ",c)

