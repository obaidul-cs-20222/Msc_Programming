# %%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
from sklearn.decomposition import PCA

# Step 1: Load the Iris dataset
iris = load_iris()
X = iris.data
y = iris.target

# Step 2: Perform KMeans Clustering
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X)
labels = kmeans.labels_

# Step 3: Determine cluster to species mapping
cluster_species_mapping = {}
for cluster in np.unique(labels):
    cluster_species = np.bincount(y[labels == cluster]).argmax()
    cluster_species_mapping[cluster] = iris.target_names[cluster_species]

# Step 4: Visualize the Clusters using PCA
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X)

plt.figure(figsize=(8, 6))
for cluster in np.unique(labels):
    label = cluster_species_mapping[cluster]
    plt.scatter(X_pca[labels == cluster, 0], X_pca[labels == cluster, 1], label=label, edgecolor='k', s=150)

plt.xlabel('PCA Component 1')
plt.ylabel('PCA Component 2')
plt.title('KMeans Clustering on Iris Dataset')
plt.legend()
plt.show()



