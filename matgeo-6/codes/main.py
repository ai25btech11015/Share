
import numpy as np
import matplotlib.pyplot as plt
import ctypes
import os

# Load DLL and call solve_triangle
dll_path = os.path.join(os.path.dirname(__file__), 'main.dll')
main = ctypes.CDLL(dll_path)
solve_triangle = main.solve


arr = np.array([1.0, 2.0, 3.0], dtype=np.float64)




solve_triangle.argtypes = [ctypes.POINTER(ctypes.c_double)]
solve_triangle.restype = None


solve_triangle(arr.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))

# Compute coordinates as in C
B_pt = np.array([0.0, 0.0])
C_pt = np.array([arr[0], 0.0])
B_rad = np.deg2rad(60)
A_pt = np.array([arr[2] * np.cos(B_rad), arr[2] * np.sin(B_rad)])

# Plot the triangle
x = [A_pt[0], B_pt[0], C_pt[0], A_pt[0]]
y = [A_pt[1], B_pt[1], C_pt[1], A_pt[1]]

plt.plot(x, y)
plt.scatter(x, y)

plt.text(A_pt[0], A_pt[1], "A")
plt.text(B_pt[0], B_pt[1], "B")
plt.text(C_pt[0], C_pt[1], "C")

plt.axhline(0, color='black')   # x-axis
plt.axvline(0, color='black')   # y-axis
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.axis("equal")

plt.savefig("../figs/fig.png", dpi=300)
