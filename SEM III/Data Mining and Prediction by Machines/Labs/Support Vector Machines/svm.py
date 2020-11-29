
#! /usr/bin/env python

from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
from sklearn.svm import SVC

dataset = load_iris()

x = dataset["data"]
y = dataset["target"]

x_train, x_test, y_train, y_test = train_test_split(x, y, train_size=0.66, random_state=3)

n_train_samples = x_train.shape[0]
n_test_samples = x_test.shape[0]

print(f"Number of training samples: {n_train_samples}")
print(f"Number of test samples: {n_test_samples}")

svm = SVC()
svm.fit(x_train, y_train)

print(f'Accuracy of SVC on training set: {svm.score(x_train, y_train):.2f}')
print(f'Accuracy of SVC on test set: {svm.score(x_test, y_test):.2f}')
