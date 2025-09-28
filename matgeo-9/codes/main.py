import numpy as np
import matplotlib.pyplot as plt

# Normal vector of the given side x + y - 2 = 0
n = np.array([1, 1])
# Direction vector perpendicular to the side (for vertex from centroid)
m = np.array([1, -1])

# Centroid at origin
centroid = np.array([0, 0])

# Candidate points for the vertex (from multiple choice)
candidates = [np.array([-1, -1]),
              np.array([2, 2]),
              np.array([-2, -2]),
              np.array([2, -2])]

# Function to check if point lies on perpendicular line through origin
def is_on_perpendicular(p, dir_vec):
    # Vector from origin
    vec = p - centroid
    # Check if parallel to dir_vec
    cross = vec[0]*dir_vec[1] - vec[1]*dir_vec[0]
    return np.isclose(cross, 0)

# Find the vertex
for pt in candidates:
    if is_on_perpendicular(pt, m):
        vertex = pt
        break

print("Vertex coordinates:", vertex)

# Now find two points on the line x + y - 2 = 0 for the other side
# Solve for y in terms of x: y = 2 - x
B = np.array([0, 2])  # x = 0
C = np.array([2, 0])  # x = 2

A = vertex

# Plot the triangle
x = [A[0], B[0], C[0], A[0]]
y = [A[1], B[1], C[1], A[1]]

plt.plot(x, y, 'bo-')
plt.text(*A, 'A', fontsize=12, ha='right')
plt.text(*B, 'B', fontsize=12, ha='right')
plt.text(*C, 'C', fontsize=12, ha='left')
plt.scatter(*centroid, color='red')
plt.text(*centroid, 'O', fontsize=12, ha='left')

plt.axis('equal')
plt.grid(True)
plt.savefig("../figs/fig.png", dpi=300)
# plt.show()
