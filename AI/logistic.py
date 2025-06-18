# Step 1: Import Libraries
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report, confusion_matrix
import matplotlib.pyplot as plt
import seaborn as sns

# Step 2: Load Data
df = pd.read_csv('data_banknote_authentication.csv')

# Step 3: Prepare Data
X = df[['F1', 'F2', 'F3','F4']]  # replace with your actual feature columns
y = df['Target']  # replace with your actual target column

# Split data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Step 4: Train the Model
log_model = LogisticRegression()
log_model.fit(X_train, y_train)

# Step 5: Make Predictions
y_pred = log_model.predict(X_test)

# Step 6: Evaluate the Model
print(classification_report(y_test, y_pred))

# Confusion Matrix
conf_matrix = confusion_matrix(y_test, y_pred)
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix')
plt.show()

# Step 7: Visualize Data
# Pairplot of the features
sns.pairplot(df, hue='target')
plt.show()

# Correlation heatmap
corr_matrix = df.corr()
sns.heatmap(corr_matrix, annot=True, cmap='coolwarm')
plt.title('Feature Correlation Matrix')
plt.show()
