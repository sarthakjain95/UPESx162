
#! /usr/bin/env python3


def returnLambda(n):
	return lambda x: x*n

my_doubler= returnLambda(2)
my_tripler= returnLambda(3)

print( my_doubler("foo") + "bar" )
print( my_tripler("foo") + "bar" )

# Q.
# How does the control flow of python interpreters work in the above code?

# A.
# 'my_doubler' is assigned to a function that returns another function that is executed
#  with the value passed in the outer function.
#
# In layman's terms, the returnLambda function returns a function that is assigned to 'my_doubler'.
# The function that is assigned to my_doubler uses a variable that was given to 'returnLambda' function
# when it was called by my_doubler. (value '2')
# So my_doubler is basically lambda x:x*2
# 
# The python interpreter would skip ahead of the function definitions up to the assignment of the variable
# my_doubler. On this line, the interpreter would jump to the function definition of 'returnLambda'.
# Which returns a lambda function to the caller. So, the interpreter would jump back to my_doubler, and 
# assign it a lambda function.
# Same transitions would playout for the next line, on the assignment of my_tripler, which again calls the 
# returnLambda function.


# ==============================


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
print("Values after function changeList2",group,"\n")

# Q.
# What is the difference between the above two codes?
# Does python give the same result with immutable collections?

# A.
# In the sets of code given above,
# 'changeList' would receive a list item as an argument in the function and try to append another list as an
# element is the given array. In this case, the changes would be reflected in the actual array passes to
# the function. 
# However, in 'changeList2', the variable 'l', that receives the passed array is assigned
# with a new value (another array), In this case, the changes would not be reflected in the array
# that was passed with the function call.
# Assigning the name to a new explicit array would give rise to a new object in the memory.
# 
# When an immutable data type is passed in a function like this, the changes would not be reflected in
# the actual variable that was passed. Due to the immutable state of the object, when it is passed 
# an argument to functions, another local copy of the variable is created and the changes are made 
# on this new memory location instead of the actual variable that was passed.


# ==============================


# Q.
# What is the data type specifier used for character values in python3 array?

# A.
# The data specifier used for character values in python3 arrays is 'b' or 'B'. 
# While 'u' is used for Unicode.


# ==============================


# Q.
# What is the difference between the pop function and the remove function in arrays?

# A.
# The pop function in python3 receives the index of the element as an argument. It removes the element
# in the corresponding index and returns the value that is removed from the list. 
# While the remove function receives the element (to be removed) itself, as an argument. It removes
# the first matching value from the list. It returns nothing and raises a ValueError if the value 
# is not found in the array. 

