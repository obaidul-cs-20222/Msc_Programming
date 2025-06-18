# %%
import numpy as np

# Sigmoid activation function and its derivative
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# Multilayer Perceptron class
class MultilayerPerceptron:
    def __init__(self, input_size, hidden1_size, hidden2_size, output_size):
        # Initialize weights and biases
        self.W1 = np.zeros((input_size, hidden1_size))  # Input -> Hidden1
        self.b1 = np.zeros((1, hidden1_size))  # Bias for Hidden1
        self.W2 = np.zeros((hidden1_size, hidden2_size))  # Hidden1 -> Hidden2
        self.b2 = np.zeros((1, hidden2_size))  # Bias for Hidden2
        self.W3 = np.zeros((hidden2_size, output_size))  # Hidden2 -> Output
        self.b3 = np.zeros((1, output_size))  # Bias for Output

    def forward(self, X):
        # Hidden Layer 1
        self.z1 = np.dot(X, self.W1) + self.b1
        self.a1 = sigmoid(self.z1)
        # Hidden Layer 2
        self.z2 = np.dot(self.a1, self.W2) + self.b2
        self.a2 = sigmoid(self.z2)
        # Output Layer
        self.z3 = np.dot(self.a2, self.W3) + self.b3
        self.y_pred = sigmoid(self.z3)
        return self.y_pred

    def backward(self, X, y, learning_rate):
        # Backpropagation
        m = X.shape[0]  # Number of samples

        # Output layer error
        delta3 = (self.y_pred - y) * sigmoid_derivative(self.y_pred)
        dW3 = np.dot(self.a2.T, delta3) / m
        db3 = np.sum(delta3, axis=0, keepdims=True) / m

        # Hidden Layer 2 error
        delta2 = np.dot(delta3, self.W3.T) * sigmoid_derivative(self.a2)
        dW2 = np.dot(self.a1.T, delta2) / m
        db2 = np.sum(delta2, axis=0, keepdims=True) / m

        # Hidden Layer 1 error
        delta1 = np.dot(delta2, self.W2.T) * sigmoid_derivative(self.a1)
        dW1 = np.dot(X.T, delta1) / m
        db1 = np.sum(delta1, axis=0, keepdims=True) / m

        # Update weights and biases
        self.W3 -= learning_rate * dW3
        self.b3 -= learning_rate * db3
        self.W2 -= learning_rate * dW2
        self.b2 -= learning_rate * db2
        self.W1 -= learning_rate * dW1
        self.b1 -= learning_rate * db1

# Sample input and target
X = np.array([[1, 0, 1]])  # Input vector (1 sample, 3 features)
y = np.array([[1, 0]])  # Target label

# Define network topology
input_size = 3
hidden1_size = 2
hidden2_size = 2
output_size = 2

# Create the MLP
mlp = MultilayerPerceptron(input_size, hidden1_size, hidden2_size, output_size)

# Training parameters
epochs = 10000
learning_rate = 0.2

# Training loop
for epoch in range(epochs):
    # Forward pass
    y_pred = mlp.forward(X)
    
    # Compute loss (Mean Squared Error)
    loss = 0.5 * np.sum((y_pred - y) ** 2)
    
    # Backward pass
    mlp.backward(X, y, learning_rate)
    
    # Print loss every 1000 epochs
    if (epoch + 1) % 1000 == 0 or epoch == 0:
        print(f"Epoch {epoch + 1}/{epochs}, Loss: {loss:.6f}")

# Final output after training
final_output = mlp.forward(X)
print("Final Predicted Output:", final_output)



