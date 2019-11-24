
# Practical 10
import numpy as np

# Q1. 
# Create numpy array to find sum of all elements in an array.

np_ar= np.array( (234,32,4,235,5,234) )
print(np_ar)
print("Sum of all elements is", np_ar.sum())



# Q2. 
# Create numpy array of (3,3) dimension. 
# Now find sum of all rows & columns individually. 
# Also find 2nd maximum element in the array. 

np_ar= np.array( () )
np_ar= np.append( np_ar, np.array((9,2,3)) )
np_ar= np.append( np_ar, np.array((6,5,4)) )
np_ar= np.append( np_ar, np.array((7,8,1)) )

np_ar= np_ar.reshape(3,3)
print( np_ar )

sorted_ar= np.array(np_ar).reshape( 1, np_ar.size )
sorted_ar.sort()

print("Sum of all Column-wise: ", np_ar.sum(axis=0))
print("Sum of all Row-wise: ", np_ar.sum(axis=1))
print( "Second biggest element is",sorted_ar.tolist()[0][-2] )

