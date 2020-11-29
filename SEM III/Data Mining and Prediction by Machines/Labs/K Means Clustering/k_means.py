
#! /usr/bin/env python

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

df = pd.DataFrame({
	'x': [12, 20, 28, 18, 29, 33, 24, 45, 45, 52, 51, 52, 55, 53, 55, 61, 64, 69, 72],
	'y': [39, 36, 30, 52, 54, 46, 55, 59, 63, 70, 66, 63, 58, 23, 14,  8, 19,  7, 24]
})

model = KMeans(n_clusters=3)
model.fit(df)

# Get Classes for the dataset
df_classes = model.predict(df)
# Assign Colors to all the classes/predictions
df_classes_colors = ["gby"[i] for i in df_classes]

# User Input predictions
x_user = int(input("Enter 'x' coordinate: "))
y_user = int(input("Enter 'y' coordinate: "))
#
df_user = pd.DataFrame({
	'x': [x_user],
	'y': [y_user]
})
#
user_class = model.predict(df_user)
print(f"Predicted class for user input is {user_class}")

# Collect the centers of all the clusters for the model
centers = model.cluster_centers_
# Collect the classes for the centers
center_classes = model.predict(centers)
# Assign colors to center points according to class
center_colors = ["gby"[i] for i in center_classes]
# Assign a label to cluster centers
center_labels = [f"class{i}"for i in center_classes]

# Scatter Dataset values and Centers of Clusters
plt.scatter(df["x"], df["y"], c=df_classes_colors)
for i in range(len(centers)):
	plt.scatter(centers[i][0], centers[i][1], c=center_colors[i], label=center_labels[i])
# Add the user input to graph
plt.scatter(df_user["x"], df_user["y"], c='r', label="user_input")
plt.legend()
plt.savefig("final_result")
plt.show()
