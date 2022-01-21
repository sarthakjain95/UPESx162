
from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression
import numpy as np

data = load_iris()
# print(data)

x, y, y_names = data["data"], data["target"], data["target_names"]
x = np.array(x)
y = np.array(y)
print(x.shape, y.shape)

# Rescaling the data
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
x =  scaler.fit_transform(x)

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=0)

logreg = LogisticRegression(random_state=12).fit(x_train, y_train)
print("LogisticRegression score: ", logreg.score(x_test, y_test))

print(logreg.predict(x_test))
print(y_test)
