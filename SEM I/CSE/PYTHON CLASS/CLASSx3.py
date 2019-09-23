#! /usr/bin/env python3

# list is a  collection that is mutable in nature
foobar = ['this','banana','apple']
print(foobar)

# Access the second item
print(foobar[1])

# Gives out an error "List index out of range"
# print(foobar[32])

# print all values in a list
print("\nPrinting the entire List:")
for i in foobar:
	print(i)

# Check if a item is in a list
if 'kiwi' in foobar:
	print("kiwi is in foobar")
else:
	print("kiwi is not in foobar")

print("Adding kiwi in foobar")
foobar.append('kiwi') #Appends new item to the end of the existing list

if 'kiwi' in foobar:
	print("kiwi is in foobar")
else:
	print("kiwi is not in foobar")

# Adds orange at index 1. Everything else after it moves.
foobar.insert(1,'orange')

# Won't work like in JS. It adds to the list index if the index is out of range
foobar.insert(32,'grapes')
print(foobar, len(foobar), foobar[4])

# Gives out error. 'david' is not in foobar
try:
	foobar.remove('david')
except:
	print("Couldn't remove david")

# Q. Check if you can use remove() with index number
try:
	foobar.remove(2)
except:
	print("Couldn't remove")
# A. Nope.

foobar.append('apple')
foobar.remove('apple')
print(foobar) # only first occurence of 'apple' removed

# del foobar[3]
# print(foobar)

del foobar
try:
	print(foobar)
except:
	print("foobar does not exist")


foo= [1,2,4,1024,16,512,64,32,128,256,512,[8,2048,[4096]]]

bar= foo.copy()
print(bar)

# Another way of creating a list is using the list method
bar= list(foo)
print(bar)

#############################################################################################3
#############################################################################################3

# Homework

# Try to use the following methods
# clear()
# count()
# extend()
# index()
# reverse()
# sort()

foo.pop()
print(foo) # foo without internal arrays
foo.sort() # sorts foo
print(foo) # [1, 2, 4, 16, 32, 64, 128, 256, 512, 512, 1024]
print(foo.reverse()) # None
print(foo.index(512)) # 1
print(foo.count(512)) # 2
print(foo.extend(bar)) # None
print(foo)

