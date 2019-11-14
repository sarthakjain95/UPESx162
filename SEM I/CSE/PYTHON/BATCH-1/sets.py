a = {2, 4, 6, 8, 10}
b = {4, 2, 3.5, (5,6)}
# s = set({})
# print(type(s))
# b.add(25)
# print(b)

#Sum of all elements in a set
sum_ = 0
for i in a:
    sum_ += i
print("Sum of all elements:", sum_)


#Union operator
print("Union of A and B is:" , a.union(b))
#Union operator using |
print("Union of A and B is (using |):" , a|b)

#Intersection operator
print("Intersection of A and B is:" , a.intersection(b))
#Intersection operator using &
print("Intersection of A and B is (using &):" , a&b)

#Difference operator (A-B)(Elements in A but not B)
print("Difference of A and B is:" , a.difference(b))
#Differenceoperator using -
print("Difference of A and B is (using &):" , a-b)

#Symmetric Difference operator (A^B)(Elements in either A or B but not both)
print("Symmetric Difference of A and B is:" , a.symmetric_difference(b))
#Symmetric Differenceoperator using ^
print("Symmetric Difference of A and B is (using &):" , a^b)
