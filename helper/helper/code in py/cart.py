# %%
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn import tree
from sklearn import metrics
from sklearn.metrics import accuracy_score, classification_report
import pandas as pd

# %%
# Reading the CSV file
df = pd.read_csv("data_banknote_authentication.csv", index_col=False) #, header = None
 
# Printing top 5 rows
#df.head()

# %%
# Remove rows with missing values
cleaned_data = df.dropna(axis=0)
# Shuffle the dataset
shuffled_df = cleaned_data.sample(n=len(cleaned_data))

# %%
# Specify the name or index of the intermediate target column
target_column_name = 'Target'  # Replace 'target_column_name' with the name of your target column

features = shuffled_df.drop(target_column_name, axis=1)
target = shuffled_df[target_column_name]

# %%
# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.3, random_state=42)

# %%
# Create a DecisionTreeClassifier (CART algorithm)
clf = DecisionTreeClassifier() 

# Train the model
clf.fit(X_train, y_train)

# Make predictions
y_pred = clf.predict(X_test)

# Evaluate the model
accuracy = metrics.accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)

# %%
# Calculate accuracy
accuracy = accuracy_score(y_test, y_pred)
print(f'CART accuracy: {accuracy:.2f}')

# Print classification report
print('Classification report:')
print(classification_report(y_test, y_pred))

# %%
tree.plot_tree(clf)


