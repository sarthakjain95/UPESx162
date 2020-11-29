
#! /usr/bin/env python

import numpy as np 
from sklearn.linear_model import LinearRegression 
import matplotlib.pyplot as plt

x = np.array([2, 3, 4, 5, 6]).reshape((-1, 1))
y = [5, 7, 9, 11, 13]

model= LinearRegression()
model.fit(x, y)

# a*x1 + b
b0= model.intercept_ #b
b1= model.coef_ #a
print("Model regenerated Equation as {} * x + {} = y".format(b1, b0))

x_ = 34
res = b1*x_ + b0
print(f"{b1}*x + {b0} = {res}")
