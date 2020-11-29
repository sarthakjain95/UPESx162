
#! /usr/bin/env python

import numpy as np
from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

data = load_boston()

x = data["data"]
y = data["target"]
y_names = data["feature_names"]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.15, random_state=42)

n_train_samples = x_train.shape[0]
n_test_samples = x_test.shape[0]
print(f"Number of training samples: {n_train_samples}")
print(f"Number of test samples: {n_test_samples}")

model = LinearRegression()
# Training Model
model.fit(x_train, y_train)

# Calculating Mean Square Error
predictions = model.predict(x_test)
mse = np.sum(np.square(predictions - y_test)) / n_test_samples
print(f"Mean square error is {mse:.2f}")

