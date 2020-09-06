
#! /usr/bin/env python

from math import log2
from pprint import pprint


def calc_entropy(class_values:list, e=1e-10) -> float:

	'''
		Calculates the entropy for a single class of a column

		ARGUMENTS:
			class_values: list of type [X, Y], where X is the number of times 
			0 appeared as label for this class. Y is the number of times 1
			appeared as label for this class.
			e= 1e-10: epsilon for avoiding math domain 
			error with log2 ```check: log2(0)``` 
	'''

	total= sum(class_values)
	ys= class_values[1]
	ns= class_values[0]
	#
	entropy= - (ys/total)*log2(ys/total+e) - (ns/total)*log2(ns/total+e)

	return entropy


def calc_gain(attribute:dict, dataset_entropy:float) -> float:

	'''
		Calculates Gain for a specific column in data

		ARGUMENTS:
			attribute: A dictionary with keys as classes of columns. These
			keys are mapped to an array of type [X, Y], where X is the number of
			times 0 appeared as label for this class. Y is the number of times 1
			appeared as label for this class.
			dataset_entropy: entropy calculated on labels for dataset
	'''

	# Calculate entropy for each class in column
	entropies= {}
	for key in attribute:
		entropies[key]= calc_entropy(attribute[key])
	# Calculate total number of 1s and 0s for entire column
	total_ys= 0
	total_ns= 0
	for key in attribute:
		total_ys+= attribute[key][1]
		total_ns+= attribute[key][0]
	# 
	total= total_ys + total_ns
	# Calculates Average Weighted Entropy
	average_weighted_entropy= 0
	for key in attribute:
		average_weighted_entropy+= sum(attribute[key])/total * entropies[key]
	# Calculates Information Gain
	info_gain= dataset_entropy - average_weighted_entropy

	return info_gain


def get_max_gain(attributes:list, overall_entropy:float) -> tuple:

	'''
		Calculates Maximum gain for a given list of attributes.
	
		ARGUMENTS:
			attributes: This is the same list of attributes produced by 
			'collect_attributes' function.
	'''

	# Calculates gain for every attribute and appends it to a list
	gains= []
	for attr in attributes:
		gain= calc_gain(attr, overall_entropy)
		gains.append(gain)

	return max(gains), gains


def calc_overall_entropy(labels:list, e=1e-8) -> float:

	'''
		This function calculate the entropy for a given set of labels

		ARGUMENTS:
			labels: list of 1s and 0s, as classes for dataset
			e=1e-8: epsilon for avoiding math domain error with log2
			```check: log2(0)```
	'''

	class_counts= [0, 0]
	total= len(labels)
	#
	for label in labels:
		class_counts[label]+= 1
	#
	cls_0_ratio= class_counts[0]/total
	cls_1_ratio= class_counts[1]/total
	overall_entropy= - (cls_0_ratio*log2(cls_0_ratio+e) + cls_1_ratio*log2(cls_1_ratio+e))

	return overall_entropy


def collect_attributes(data:list, labels:list) -> list:

	'''
		This function calculates and returns the number true or false
		labels for all classes among all columns.

		ARGUMENTS:
			data: Features as 2D list.  
			labels: List of labels for the give data.

		RETURN VALUE:
			attributes: A list of dictionaries. Each dictionary represents number
			of column in the given data. Each dictionary has a seperate key for 
			seperate classes for that specific column. Each key is mapped to an
			array [X, Y], where 'X' is the number of rows ('data samples') for 
			which the result is 0. And Y is the number of rows for which the
			result is 1.
	'''

	attributes= []
	# 
	for column in range(len(data[0])):
		attr= {}
		for row in range(len(data)):
			k= data[row][column]
			if k not in attr:
				attr[k]= [0, 0]
			attr[k][ labels[row] ] += 1
		# 
		attributes.append(attr)

	return attributes


def make_decision_tree(header, features, labels, node:dict):

	'''
		Recursive function that produces a decision tree in form of a 
		dictionary.

		ARGUMENTS:
			header: List of names of the column in dataset.
			features: Features as 2D list.
			labels: List of end labels for the given features. Only 
			configured for 0 or 1 in this script.
			node: An empty dictionary node that maps to the full decision 
			tree as a node. 
	'''

	''' DIMENSION CHECKS '''
	assert len(header) == len(features[0])
	assert len(features) == len(labels)
	''''''

	''' Gets the column which has the maximum gain '''
	column_wise_attributes= collect_attributes(features, labels)
	overall_entropy= calc_overall_entropy(labels)
	max_gain, gains= get_max_gain(column_wise_attributes, overall_entropy)
	max_gain_column_index= gains.index(max_gain)
	''''''

	''' Divides the current dataset among the classes of MaxGain Column '''
	sub_datasets= []
	header_name= header[ max_gain_column_index ]
	node[ header_name ]= {}
	#
	column_classes= list(column_wise_attributes[ max_gain_column_index ].keys())
	for i in range(len(column_classes)):
		sub_datasets.append({
			"features": [],
			"labels": []
		})
		node[ header_name ][ column_classes[i] ]= {}
	#
	for row in range(len(features)):
		# Collect a copy of row from features
		row_features= features[row][:]
		row_class= row_features[ max_gain_column_index ]
		row_class_index= column_classes.index(row_class)
		# Remove the column that has maximum gain
		del row_features[ max_gain_column_index ]
		# Add the filtered row of features to sub-dataset
		sub_datasets[ row_class_index ]["features"].append(row_features)
		sub_datasets[ row_class_index ]["labels"].append(labels[row])
	''''''

	# Make a copy of header (else it will affect other recursion instances)
	header= header[:]
	# Remove the column with max gain from the header
	del header[ max_gain_column_index ]

	''' Generate decision tree for Sub-Datasets '''
	for i in range(len(sub_datasets)):
		# Collect sub-dataset
		sub_dataset= sub_datasets[i]
		if len(header) == 1: # Leaf node case
			for j in range(len(sub_dataset["features"])):
				feature= sub_dataset["features"][j][0]
				if feature not in node[header_name][column_classes[i]]:
					node[header_name][column_classes[i]][feature]= []
				# Add corresponding labels to leaf nodes
				node[header_name][column_classes[i]][feature].append( sub_dataset["labels"][j] )  
		else: # Sub-tree case
			make_decision_tree(header, sub_dataset["features"], sub_dataset["labels"], node[ header_name ][ column_classes[i] ])
	''''''

	return


''' DATASET '''
header= ["outlook", "temperature", "humidity", "wind"]
dataset= [
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
# 
labels= [0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0]
''''''

''' DATASET CHECKS '''
assert len(labels) == len(dataset)
assert len(header) == len(dataset[0])
''''''

decision_tree= {}
make_decision_tree(header, dataset, labels, decision_tree)
pprint( decision_tree )
