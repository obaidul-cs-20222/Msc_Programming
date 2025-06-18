# %%
import pandas as pd
import numpy as np
from sklearn.tree import export_graphviz
import graphviz

# Load your dataset
data = pd.read_csv('golf.csv')  # Replace 'your_dataset.csv' with your actual dataset file

# Calculate entropy
def entropy(target_col):
    elements, counts = np.unique(target_col, return_counts=True)
    entropy = -np.sum([(counts[i]/np.sum(counts))*np.log2(counts[i]/np.sum(counts)) for i in range(len(elements))])
    return entropy

# Calculate information gain
def info_gain(data, split_attribute_name, target_name="Play"):
    total_entropy = entropy(data[target_name])
    vals, counts = np.unique(data[split_attribute_name], return_counts=True)
    
    weighted_entropy = np.sum([(counts[i]/np.sum(counts))*entropy(data.where(data[split_attribute_name]==vals[i]).dropna()[target_name]) for i in range(len(vals))])
    Information_Gain = total_entropy - weighted_entropy
    return Information_Gain

# ID3 Algorithm
def ID3(data, originaldata, features, target_attribute_name="Play", parent_node_class=None):
    if len(np.unique(data[target_attribute_name])) <= 1:
        return np.unique(data[target_attribute_name])[0]
    elif len(data) == 0:
        return np.unique(originaldata[target_attribute_name])[np.argmax(np.unique(originaldata[target_attribute_name], return_counts=True)[1])]
    elif len(features) == 0:
        return parent_node_class
    else:
        parent_node_class = np.unique(data[target_attribute_name])[np.argmax(np.unique(data[target_attribute_name], return_counts=True)[1])]
        
        item_values = [info_gain(data, feature, target_attribute_name) for feature in features]
        best_feature_index = np.argmax(item_values)
        best_feature = features[best_feature_index]
        
        tree = {best_feature: {}}
        features = [i for i in features if i != best_feature]
        
        for value in np.unique(data[best_feature]):
            sub_data = data.where(data[best_feature] == value).dropna()
            subtree = ID3(sub_data, data, features, target_attribute_name, parent_node_class)
            tree[best_feature][value] = subtree
            
        return tree

# Prepare features and target
features = data.columns[:-1]  # All columns except the target column
target = data.columns[-1]  # The target column

# Generate the decision tree
decision_tree = ID3(data, data, features)
print(decision_tree)

# Function to visualize the decision tree using graphviz
def visualize_tree(tree, parent_name='', graph=None):
    if graph is None:
        graph = graphviz.Digraph(format='png')
    
    for key, value in tree.items():
        if isinstance(value, dict):
            node_name = f'{parent_name}\n{key}'
            graph.node(node_name)
            if parent_name:
                graph.edge(parent_name, node_name)
            visualize_tree(value, parent_name=node_name, graph=graph)
        else:
            node_name = f'{parent_name}\n{key}={value}'
            graph.node(node_name, shape='box')
            graph.edge(parent_name, node_name)
    
    return graph

# Visualize the tree
graph = visualize_tree(decision_tree)
graph.render('id3_decision_tree')



