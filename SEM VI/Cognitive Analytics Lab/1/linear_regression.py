
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt
import numpy as np

n_samples = 1000
a, b = 3.5, 1.3
data = np.random.randn(n_samples, 2)
noise = np.random.randn(n_samples)
data[:, 1] = data[:, 0] * a + b + noise

plt.plot(data[:, 0], data[:, 1], 'o')

x, y = data[:, 0].reshape(-1, 1), data[:, 1].reshape(-1, 1)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=0)

linreg = LinearRegression().fit(x_train, y_train)

from sklearn.metrics import mean_squared_error
print("LinearRegression Error: ", mean_squared_error(linreg.predict(x_test), y_test))

plt.plot(data[:, 0], linreg.intercept_[0] + linreg.coef_[0] * data[:, 0], '-')
plt.show()
