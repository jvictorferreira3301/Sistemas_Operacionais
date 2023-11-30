import pandas as pd
import glob
import matplotlib.pyplot as plt
import os

arquivos_swap = glob.glob('*gb.txt')
memoria = {}
for arquivo in arquivos_swap:
    df = pd.read_table(arquivo, sep='\s+', skiprows=1 )
    nome_arquivo_sem_extensao = os.path.splitext(os.path.basename(arquivo))[0]
    memoria[nome_arquivo_sem_extensao] = df


# for dicionario in memoria:
#     plt.title(f'Gráfico de {dicionario}')
#     (-memoria[dicionario]['livre'] + (7.62*1024*1024)).plot()
#     plt.autoscale()
#     plt.tight_layout()
#     plt.show()

num_plots = len(memoria)
fig, axs = plt.subplots(1, num_plots, figsize=(15, 5))

for i, dicionario in enumerate(memoria):
    axs[i].set_title(f'Gráfico de {dicionario}')
    axs[i].plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024))
    axs[i].autoscale()
    axs[i].set_xlabel('Tempo (s)')
    axs[i].set_ylabel('Memória Usada')
    axs[i].grid(True)
plt.tight_layout()
plt.show()


num_plots = len(memoria)
fig, ax = plt.subplots(figsize=(15, 5))

for i, dicionario in enumerate(memoria):
    ax.plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024), label=f'{8*i}GB de memória de Swap')

ax.set_title('Gráficos do Uso da Memória')
ax.set_xlabel('Tempo (s)')
ax.set_ylabel('Quantidade de Memória (GB)')
ax.legend()
ax.autoscale()
ax.grid(True)

plt.tight_layout()
plt.show()

    # if 'livre' in df.columns:
    #     df['livre'].plot()
    #     plt.title(f'Gráfico de {arquivo}')
    #     plt.autoscale()
    #     plt.show()
    # else:
    #     print(f'O arquivo {arquivo} não possui a coluna "livre"')
