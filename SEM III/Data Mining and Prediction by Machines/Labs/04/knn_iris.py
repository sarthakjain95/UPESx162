
#! /usr/bin/env python

from sklearn import datasets
import random
random.seed(42)
# import matplotlib.pyplot as plt

dataset = datasets.load_iris()
data, labels = dataset["data"], dataset["target"]

total_samples = len(data)

# Randomize data
random_indices = random.sample(list(range(total_samples)), total_samples)
data = data[random_indices]
labels = labels[random_indices]

# Get number of samples in each set
test_train_ratio = 0.80
train_size = int(total_samples * test_train_ratio)
test_size = total_samples - train_size
#
print(f"Train size: {train_size}")
print(f"Test size: {test_size}")
print(f"Number of features: {data.shape[1]}")
# Split data
train_data = data[:train_size]
# print(train_data.shape)
train_labels = labels[:train_size]
test_data = data[train_size:]
test_labels = labels[train_size:]

###########
## MODEL
###########

def predict(samples, labels, test_values, k):

	distances = []

	for sample_features in samples:
		sums = 0
		for i in range(len(sample_features)):
			sums += (sample_features[i] - test_values[i]) ** 2
		distance = sums**0.5
		distances.append(distance)

	distances_labels_zip = zip(distances, labels)
	distances_labels_zip_sorted = sorted(distances_labels_zip, key= lambda a: a[0]) # a[0] is distance
	distances_sorted, labels_sorted = list(zip(*distances_labels_zip_sorted))

	# print(distances_sorted)

	first_k_labels = labels_sorted[:k]

	frequencies = {}
	max_frequency = 0 # default value index
	max_frequency_label = first_k_labels[0]
	
	for l in first_k_labels:
		if l not in frequencies:
			frequencies[l] = 1
		else:
			frequencies[l] += 1
		# Update max frequency
		if frequencies[l] > max_frequency:
			max_frequency = frequencies[l]
			max_frequency_label = l

	return max_frequency_label, max_frequency


# Calculating accuracy

correct = 0
total = test_size
k = int((train_size)**0.5)
# k = -1
print(f"k is {k}")
#
for i in range(test_size):
	prediction, _ = predict(train_data, train_labels, test_data[i], k)
	if prediction == test_labels[i]:
		correct += 1

accuracy = (correct/total) * 100
print(f"Accuracy is {accuracy:.2f}% ({correct}/{total})")

# Arbitrary value
prediction, _ = predict(train_data, train_labels, [6.8, 4, 5.6, 8], k)
print(f'Predicted class {prediction}')
