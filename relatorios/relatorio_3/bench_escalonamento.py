import matplotlib.pyplot as plt

# Nomes dos algoritmos
algoritmos = ["SJF", "SRTF", "Prioridades", "Round Robin", "FCFS"]

# Tempos Médios de Espera (substitua pelos valores reais)
tempo_medio_espera = [112.90, 101.60, 107.60, 213.63, 111.60]

# Tempos Médios de Retorno (substitua pelos valores reais)
tempo_medio_retorno = [122.13, 110.13, 115.43, 223.03, 119.80]

# Largura das barras
largura = 0.35

# Posições no eixo x para os algoritmos
x = range(len(algoritmos))

# Criação da figura e dos eixos
fig, ax = plt.subplots()

# Adiciona barras para Tempos Médios de Espera
bar1 = ax.bar(x, tempo_medio_espera, largura, label='Tempo Médio de Espera')

# Adiciona barras para Tempos Médios de Retorno
bar2 = ax.bar([i + largura for i in x], tempo_medio_retorno, largura, label='Tempo Médio de Retorno')

# Rótulos do eixo x
ax.set_xticks([i + largura / 2 for i in x])
ax.set_xticklabels(algoritmos)

# Legenda
ax.legend()

# Rótulos dos eixos
plt.xlabel('Algoritmo')
plt.ylabel('Tempo Médio')
plt.title('Comparação dos Tempos Médios de Espera e Retorno')

# Exibe o gráfico
plt.tight_layout()
plt.show()
