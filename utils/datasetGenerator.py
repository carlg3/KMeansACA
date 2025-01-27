# it creates a MxN matrix of random values -- carlg
import numpy as np

def write_matrix(M, N):
    matrix = np.random.randint(0, 10, (M, N))
    np.savetxt(f"DataSet{M}x{N}.txt", matrix, fmt = "%d", delimiter = ",")

# write_matrix(1000, 3)
# write_matrix(1500, 3)
# write_matrix(3000, 3)
# write_matrix(5000, 3)
# write_matrix(10000, 10)
# write_matrix(40000, 10)
# write_matrix(50000, 10)
# write_matrix(100000, 10)
write_matrix(1000, 2)

print("Done!")

# snippet for plotting a 2D dataset 
# ---------------------------------
# data = [eval(line.rstrip("\n")) for line in open("dataset_100x2.txt", "r")]   
# x, y = zip(*data)
# plt.scatter(x, y)
# plt.show()