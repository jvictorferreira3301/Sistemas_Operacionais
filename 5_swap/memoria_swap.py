import numpy as np
import time

# Função para realizar operações com as matrizes
def operate_matrices():
    matrix1 = np.random.rand(10000, 10000)
    matrix2 = np.random.rand(10000, 10000)
    a = matrix1 + matrix2
    b = np.dot(matrix1, matrix2)
    return None


def main():    
    num_iterations = 2
    for i in range(num_iterations):
        operate_matrices()

if __name__ == "__main__":
    main()