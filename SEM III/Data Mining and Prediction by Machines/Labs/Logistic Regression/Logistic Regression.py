
#! /usr/bin/env python

import numpy as np
from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

dataset = load_iris()
x, y = dataset["data"], dataset["target"]
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.20, random_state=21)

model = LogisticRegression()
model.fit(x_train, y_train)

train_accuracy = model.score(x_train, y_train) * 100
test_accuracy = model.score(x_test, y_test) * 100

print(f"\nModel accuracy on training set: {train_accuracy:.2f}%")
print(f"Model accuracy on test set: {test_accuracy:.2f}%\n")

user_input_values = []
for header in dataset["feature_names"]:
	inp = float(input(f"Input {header}: "))
	user_input_values.append(inp)

user_input_values = np.array(user_input_values).reshape((-1, 4))
prediction = model.predict(user_input_values)
prediction_label = dataset["target_names"][prediction][0]

print(f"\nPredicted flower for given values is {prediction_label}({prediction[0]})\n")
