# %%
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import pandas as pd
from sklearn.preprocessing import LabelEncoder
# Load your data
rawData = pd.read_csv("buy computer.csv")
le = LabelEncoder()
rawData['age'] = le.fit_transform(rawData['age'])
rawData['income'] = le.fit_transform(rawData['income'])
rawData['student'] = le.fit_transform(rawData['student'])
rawData['credit_rating'] = le.fit_transform(rawData['credit_rating'])
rawData['Buy_Computer'] = le.fit_transform(rawData['Buy_Computer'])
# Shuffle the dataset
shuffled_data = rawData.sample(n=len(rawData))

# Remove rows with missing values
cleaned_data = shuffled_data.dropna(axis=0)

# Specify the name or index of the target column
target_column_name = 'Buy_Computer'  

# Separate the DataFrame into features and target
features = cleaned_data.drop(target_column_name, axis=1)
target = cleaned_data[target_column_name]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.2, random_state=42)

# Create and configure the MLPClassifier
mlp = MLPClassifier(hidden_layer_sizes=(100, 50),  # Two hidden layers (100 and 50 neurons)
                    activation='relu',             # Activation function (ReLU)
                    solver='adam',                 # Optimization solver (Adam)
                    max_iter=1000,                 # Maximum iterations
                    random_state=42)

# Train the model
mlp.fit(X_train, y_train)

# Make predictions
y_pred = mlp.predict(X_test)

# Evaluate the model using classification metrics
accuracy = accuracy_score(y_test, y_pred)
classification_rep = classification_report(y_test, y_pred)
conf_matrix = confusion_matrix(y_test, y_pred)

print(f"Accuracy: {accuracy:.2f}")
print("Classification Report:\n", classification_rep)
print("Confusion Matrix:\n", conf_matrix)



