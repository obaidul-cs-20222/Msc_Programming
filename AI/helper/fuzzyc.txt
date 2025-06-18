# %%
from sklearn.datasets import fetch_california_housing
import numpy as np
import skfuzzy as fuzz
import matplotlib.pyplot as plt
# Load dataset
california = fetch_california_housing()
data = california.data

# Select a subset of features for clustering (e.g., first two features for simplicity)
data_subset = data[:, :2]


# %%
# Define number of clusters
n_clusters = 3

# Apply Fuzzy C-Means
cntr, u, u0, d, jm, p, fpc = fuzz.cluster.cmeans(
    data_subset.T, n_clusters, 2, error=0.005, maxiter=1000, init=None)

# Get cluster membership indices
cluster_membership = np.argmax(u, axis=0)


# %%

# Plot the clusters
for i in range(n_clusters):
    plt.scatter(data_subset[cluster_membership == i, 0], 
                data_subset[cluster_membership == i, 1], label=f'Cluster {i}')
plt.xlabel(california.feature_names[0])
plt.ylabel(california.feature_names[1])
plt.legend()
plt.title('Fuzzy C-Means Clustering')
plt.show()



