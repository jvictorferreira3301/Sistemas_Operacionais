import pandas as pd
import glob
import matplotlib.pyplot as plt
import os

arquivos_swap = glob.glob('*.txt')
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
    axs[i].set_xlabel('Índice')
    axs[i].set_ylabel('Valor ajustado')
    axs[i].grid(True)
plt.tight_layout()
plt.show()


num_plots = len(memoria)
fig, ax = plt.subplots(figsize=(15, 5))

for i, dicionario in enumerate(memoria):
    ax.plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024), label=f'{dicionario}')

ax.set_title('Gráficos de Memória')
ax.set_xlabel('Índice')
ax.set_ylabel('Valor ajustado')
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
