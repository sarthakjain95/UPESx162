
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



import array as arr
# array( datatype, values )
ar= arr.array( 'd', [ 1.1, 324.3434534, 234234.234324 ] )
print(ar)
print("Length of your array is {}".format(len(ar)))



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

print(c)
