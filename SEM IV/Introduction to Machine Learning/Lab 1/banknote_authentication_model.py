
#! /usr/bin/env python

import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split
from tensorflow.keras.layers import Dense
from tensorflow.keras.losses import BinaryCrossentropy

with open("data_banknote_authentication.txt", 'r') as f:
	content = f.readlines()

data = [list(map(float, line.strip().split(','))) for line in content]
data = np.array(data)

class_values = data[:, -1].astype(np.int8)
data = data[:, 0:-1]

x, y = data, class_values
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.20, random_state=42)

model = tf.keras.models.Sequential()

model.add(Dense(4, activation="relu"))
model.add(Dense(12, activation='relu'))
model.add(Dense(6, activation='relu'))
model.add(Dense(2, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

model.compile(
	optimizer='adam', 
	loss=BinaryCrossentropy(),
	metrics=['accuracy']
	)

model.fit(x_train, y_train, epochs=10, batch_size=16)

_, test_accuracy = model.evaluate(x_test, y_test, batch_size=16)
print(f"\nTest accuracy: {test_accuracy*100:.2f}%")
