import matplotlib.pyplot as plt

# Dados
arquivos = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"]
sequential_write = [3.78, 3.83, 3.84, 3.89, 5.60, 3.78, 4.47, 3.85, 3.79, 3.74, 4.41, 3.93]
sequential_read = [1.03, 0.27, 0.30, 0.28, 0.92, 2.85, 0.32, 2.77, 0.27, 10.79, 5.73, 6.96]
random_write = [8.84, 9.19, 9.85, 9.58, 9.28, 8.28, 10.62, 8.95, 12.84, 11.59, 14.69, 12.52]
random_read = [0.71, 0.71, 0.73, 0.71, 0.75, 0.72, 0.72, 0.75, 0.71, 0.71, 0.70, 0.71]

# Criar gráfico para Escrita Sequencial
plt.figure(figsize=(6, 4))
plt.bar(arquivos, sequential_write, color='blue')
plt.title('Escrita Sequencial')
plt.ylabel('Tempo (segundos)')
plt.xlabel('Arquivos')
plt.ylim([0, 15])
plt.show()

# Criar gráfico para Leitura Sequencial
plt.figure(figsize=(6, 4))
plt.bar(arquivos, sequential_read, color='green')
plt.title('Leitura Sequencial')
plt.ylabel('Tempo (segundos)')
plt.xlabel('Arquivos')
plt.ylim([0, 15])
plt.show()

# Criar gráfico para Escrita Aleatória
plt.figure(figsize=(6, 4))
plt.bar(arquivos, random_write, color='red')
plt.title('Escrita Aleatória')
plt.ylabel('Tempo (segundos)')
plt.xlabel('Arquivos')
plt.ylim([0, 15])
plt.show()

# Criar gráfico para Leitura Aleatória
plt.figure(figsize=(6, 4))
plt.bar(arquivos, random_read, color='purple')
plt.title('Leitura Aleatória')
plt.ylabel('Tempo (segundos)')
plt.xlabel('Arquivos')
plt.ylim([0, 15])
plt.show()
