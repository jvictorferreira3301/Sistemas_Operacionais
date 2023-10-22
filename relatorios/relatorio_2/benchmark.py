import matplotlib.pyplot as plt

# Tempos médios obtidos das simulações
tempos_fork = [0.053080, 0.113790, 0.177631]
tempos_thread = [0.032997, 0.065501, 0.099919]  

# Número de simulações
num_simulacoes = len(tempos_fork)

# Gere números de simulação para o eixo x
simulacoes = list(range(1, num_simulacoes + 1))

largura_barra = 0.4
deslocamento = largura_barra

# Crie um gráfico de barras para comparar os tempos
plt.figure(figsize=(10, 5))
plt.bar([sim + deslocamento for sim in simulacoes], tempos_fork, width=largura_barra, label='Usando fork')
plt.bar(simulacoes, tempos_thread, width=largura_barra, label='Usando threads')
plt.xlabel('Execução')
plt.ylabel('Tempo médio (segundos)')
plt.title('Comparação de Desempenho: fork vs. Threads')
plt.legend()
plt.xticks([sim + deslocamento for sim in simulacoes], simulacoes)
plt.show()
