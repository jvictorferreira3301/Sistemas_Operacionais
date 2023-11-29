import numpy as np
import time

# Função para realizar operações com as matrizes
def operate_matrices():
    matrix1 = np.random.rand(1000, 1000)
    matrix2 = np.random.rand(1000, 1000)
    return matrix1 + matrix2, np.dot(matrix1, matrix2)

# Realizar repetidas contas com as matrizes e armazenar mais resultados intermediários
num_iterations = 240
results_sum = []
results_product = []

for i in range(num_iterations):
    sum_result, product_result = operate_matrices()
    results_sum.append(sum_result)
    results_product.append(product_result)
    # Exibindo alguns resultados a cada 10 iterações
    if i % 10 == 0:
        print(f"Iteration {i}: Stored {len(results_sum)} sum results")
        print(f"Iteration {i}: Stored {len(results_product)} product results")
        time.sleep(.5)

# Liberar memória
for result_sum,result_product in zip(results_sum,results_product):
    del result_sum
    del result_product
