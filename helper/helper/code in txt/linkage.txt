# %%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from scipy.cluster.hierarchy import dendrogram, linkage
from scipy.cluster.hierarchy import fcluster

# Load the Iris dataset
iris = load_iris()
X = iris.data
y = iris.target


# %%
# Single Linkage
Z_single = linkage(X, method='single')
# Complete Linkage
Z_complete = linkage(X, method='complete')
# Average Linkage
Z_average = linkage(X, method='average')


# %%
plt.figure(figsize=(16, 5))

# Single Linkage Dendrogram
plt.subplot(1, 3, 1)
dendrogram(Z_single)
plt.title('Single Linkage Dendrogram')
plt.xlabel('Sample Index')
plt.ylabel('Distance')

# Complete Linkage Dendrogram
plt.subplot(1, 3, 2)
dendrogram(Z_complete)
plt.title('Complete Linkage Dendrogram')
plt.xlabel('Sample Index')
plt.ylabel('Distance')

# Average Linkage Dendrogram
plt.subplot(1, 3, 3)
dendrogram(Z_average)
plt.title('Average Linkage Dendrogram')
plt.xlabel('Sample Index')
plt.ylabel('Distance')

plt.tight_layout()
plt.show()


# %%
# Single Linkage Clusters
clusters_single = fcluster(Z_single, t=3, criterion='maxclust')
# Complete Linkage Clusters
clusters_complete = fcluster(Z_complete, t=3, criterion='maxclust')
# Average Linkage Clusters
clusters_average = fcluster(Z_average, t=3, criterion='maxclust')

# Print cluster labels
print("Clusters from Single Linkage:", clusters_single)
print("Clusters from Complete Linkage:", clusters_complete)
print("Clusters from Average Linkage:", clusters_average)



