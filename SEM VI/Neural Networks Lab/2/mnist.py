
# 2.  Initialize Hyper-parameters
# 5.  Build the Feedforward Neural Network
# 6.  Instantiate the FNN
# 8.  Choose the Loss Function and Optimizer
# 9.  Training the FNN Model
# 10. Testing the FNN Model
# 11. Save the trained FNN Model for future use

# Import torch

import torch
import torch.nn as nn 
import torchvision
import matplotlib.pyplot as plt

# Device configuration

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(f"Running on '{device}'")

# Downloading dataset

from torchvision import datasets

train_data = datasets.MNIST(
    root = 'data',
    train = True,                         
    download = True,            
)

test_data = datasets.MNIST(
    root = 'data', 
    train = False, 
    download = True,
)

# Loading dataset

train_labels = train_data.targets
test_labels = test_data.targets
train_data = train_data.data
test_data = test_data.data

print(f"train_data.shape:{train_data.shape} test_data.shape:{test_data.shape}")

# # Exploring data

plt.imshow(train_data[0], cmap='gray')
plt.show()

# Set hyperparameters

n_train_sample = train_data.shape[0]
n_test_samples = test_data.shape[0]

image_size = train_data.shape[-1]
input_size = image_size * image_size
hidden_layer_size = 512
n_classes = 10

n_iters = 50
batch_size = 2000
lr = 0.001

# Transform data

train_data = train_data.to(torch.float32)/255.
test_data = test_data.to(torch.float32)/255.
train_data = train_data.reshape(-1, input_size)
test_data = test_data.reshape(-1, input_size)

# Store all data on gpu 

train_data = train_data.to(device)
test_data = test_data.to(device)
train_labels = train_labels.to(device)
test_labels = test_labels.to(device)

# Making model

class FFNN(nn.Module):

    def __init__(self, input_size, hidden_layer_size, n_classes):
        super(FFNN, self).__init__()
        self.input_size = input_size
        self.hidden_layer_size = hidden_layer_size
        self.n_classes = n_classes
        # Adding layers
        self.l1 = nn.Linear(input_size, hidden_layer_size)
        self.l1_activation = nn.ReLU()
        self.l2 = nn.Linear(hidden_layer_size, n_classes)

    def forward(self, x):
        z = self.l1(x)
        a = self.l1_activation(z)
        z2 = self.l2(a)
        return z2

# Making model and training

ffnn = FFNN(input_size, hidden_layer_size, n_classes)
ffnn.to(device)

# Loss and Optimizer

criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(ffnn.parameters(), lr=lr)

# Training 

losses = []
test_losses = [] 

for epoch in range(n_iters):
    avg, c = 0, 0
    for idx in range(0, n_train_sample, batch_size):
        # Get images and labels for current epoch
        batch_x = train_data[idx:idx+batch_size]
        batch_labels = train_labels[idx:idx+batch_size]
        # Forward pass
        predictions = ffnn.forward(batch_x)
        # Compute Loss
        loss = criterion(predictions, batch_labels)
        losses.append(float(loss))
        avg, c = avg+loss, c+1
        # Backprop 
        optimizer.zero_grad() # Reset gradients
        loss.backward() # Recompute gradients
        optimizer.step() # Update weights
        print(f"Epoch:{epoch+1}\tBatch:{idx}\tLoss:{loss}")
    # Output loss every 100 epochs
    if ((epoch + 1) % 5) == 0:
        print(f"Epoch:{epoch+1}\tAverageLoss:{(avg/c)}")
        # Compute loss on test set
        predictions = ffnn.forward(test_data)
        test_loss = criterion(predictions, test_labels)
        test_losses.append(float(test_loss))

# Plot losses

plt.plot(losses)
plt.title("Training Loss")
plt.show()

# Plot test losses

plt.plot(test_losses)
plt.title("Test Losses")
plt.show()

# Finally compute loss on both sets once more

predictions = ffnn.forward(train_data)
train_loss = criterion(predictions, train_labels)
print(f"Loss on train set: {train_loss}")

predictions = ffnn.forward(test_data)
test_loss = criterion(predictions, test_labels)
print(f"Loss on test set: {test_loss}")

# Save model for future use

torch.save(ffnn.state_dict(), "./ffnn_mnist.torch")
