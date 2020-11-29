
#! /usr/bin/env python

import pprint

header= ["age", "income", "si_due", "credit_score"]
data= [
	["youth", "high", "no", "fair"],
	["youth", "high", "no", "excellent"],
	["middle", "high", "no", "fair"],
	["senior", "medium", "no", "fair"],
	["senior", "low", "yes", "fair"],
	["senior", "low", "yes", "excellent"],
	["middle", "low", "yes", "excellent"],
	["youth", "medium", "no", "fair"],
	["youth", "low", "yes", "fair"],
	["senior", "medium", "yes", "fair"],
	["youth", "medium", "yes", "excellent"],
	["middle", "medium", "no", "excellent"],
	["middle", "high", "yes", "fair"],
	["senior", "medium", "no", "excellent"]
]
labels= [0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0]


input_values= {}
# 
for column_name in header:
	input_values[column_name]= input(f"Enter {column_name}: ")

r_yes= 1
r_no = 1
# 
p_yes = labels.count(1) / len(labels)
p_no = labels.count(0) / len(labels)
#
column_label_map= {}
# 
for i in range(len(header)):

	column_name= header[i]
	column_label_map[column_name]= [0, 0]

	for row in data:
		if row[ header.index(column_name) ] == input_values[column_name]:
			column_label_map[column_name][labels[i]] += 1

	# Calculate ratio 
	ry= column_label_map[column_name][1]/labels.count(1)
	rn= column_label_map[column_name][0]/labels.count(0)

	# Ignore a ratio if it is zero.
	if ry != 0: r_yes *= ry
	if rn != 0: r_no *= rn

# Include label ratios
r_yes *= p_yes
r_no *= p_no

# Calculate probabilities
p_yes = r_yes / (r_yes + r_no)
p_no = r_no / (r_yes + r_no)

print(f"Probability for yes is {p_yes*100:.2f}%")
print(f"Probability for no is {p_no*100:.2f}%")

if p_yes > p_no : print(f"Prediction is {1}")
else: print(f"Prediction is {0}")
