
#! /usr/bin/env python

import pandas as pd
import numpy as np
from sklearn.tree import DecisionTreeClassifier

# Dataset
headers = ["outlook", "temperature", "humidity", "wind"]
dataset = [
	["sunny", "hot", "high", "weak"],
	["sunny", "hot", "high", "strong"],
	["overcast", "hot", "high", "weak"],
	["rain", "mild", "high", "weak"],
	["rain", "cool", "normal", "weak"],
	["rain", "cool", "normal", "strong"],
	["overcast", "cool", "normal", "strong"],
	["sunny", "mild", "high", "weak"],
	["sunny", "cool", "normal", "weak"],
	["rain", "mild", "normal", "weak"],
	["sunny", "mild", "normal", "strong"],
	["overcast", "mild", "high", "strong"],
	["overcast", "hot", "normal", "weak"],
	["rain", "mild", "high", "strong"]
]

# Played football ? yes/no
labels = [0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0]

# Dataset checks
assert len(labels) == len(dataset)
assert len(headers) == len(dataset[0])

# Conversion maps
header_encoding_map = {
	"outlook": {"sunny": 0, "overcast": 1, "rain": 2 },
	"temperature": { "mild": 0, "hot": 1, "cool": 2 },
	"humidity": { "high": 0, "normal": 1 },
	"wind": { "weak": 0, "strong": 1 }
}
label_encoding_to_label_map = {
	1: "yes",
	0: "no"
}

df = pd.DataFrame(dataset, columns=headers)

# Map values in dataset to encoded integer values
for header in headers:
	df[header] = df[header].map(header_encoding_map[header])

print("\nEncoded dataset is")
print(df)
print()

# Make decision tree
decision_tree = DecisionTreeClassifier()
decision_tree.fit(df, labels)

# Get values from user
user_inputs = []
for header in headers:
	print(f"Input value for {header} ", end="")
	options = ",".join(header_encoding_map[header].keys())
	value = input(f"(one of {options}): ")
	user_inputs.append(value)

# Convert user inputs to data frame
user_inputs = pd.DataFrame([user_inputs], columns=headers)

# Convert user inputs to encoded values
for header in headers:
	user_inputs[header] = user_inputs[header].map(header_encoding_map[header])

print("\nEncoded user input is")
print(user_inputs)

encoded_predictions = decision_tree.predict(user_inputs)
prediction = label_encoding_to_label_map[encoded_predictions[0]]

print(f"\nPrediction is {prediction}")
