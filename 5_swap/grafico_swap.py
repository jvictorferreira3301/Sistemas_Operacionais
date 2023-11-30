import pandas as pd
import glob
import matplotlib.pyplot as plt
import os
import numpy as np

def identify_axes(ax_dict, fontsize=48):
    """
    Helper to identify the Axes in the examples below.

    Draws the label in a large font in the center of the Axes.

    Parameters
    ----------
    ax_dict : dict[str, Axes]
        Mapping between the title / label and the Axes.
    fontsize : int, optional
        How big the label should be.
    """
    kw = dict(ha="center", va="center", fontsize=fontsize, color="darkgrey")
    for k, ax in ax_dict.items():
        ax.text(0.5, 0.5, k, transform=ax.transAxes, **kw)


def plot_map(memoria):
    num_plots = len(memoria)
    # fig, axs = plt.subplots(1, num_plots, figsize=(15, 15))

    # for i, dicionario in enumerate(memoria):
        # axs[i].set_title(f'Gráfico de {8*i}GB de memória de Swap')
        # axs[i].plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024))
        # axs[i].autoscale()
        # axs[i].set_xlabel('Tempo (s)')
        # axs[i].set_ylabel('Quantidade de Memória usada (GB)')
        # axs[i].grid(True)
    # plt.tight_layout()
    # plt.show()

    fig, axs = plt.subplots(2, num_plots, figsize=(15, 15))

    for i, dicionario in enumerate(memoria):
        axs[0,i].set_title(f'Gráfico de {8*i}GB de memória de Swap')
        axs[0,i].plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024)) # O vmstat diz quanto de memoria livre temos, e quero verificar a memoria usada
        axs[0,i].autoscale()
        axs[0,i].set_xlabel('Tempo (s)')
        axs[0,i].set_ylabel('Quantidade de Memória usada (GB)')
        axs[0,i].grid(True)
        axs[1,i].set_title(f'Gráfico do Uso da Memória de Swap')
        axs[1,i].plot(memoria[dicionario]['swpd'])
        axs[1,i].autoscale()
        axs[1,i].set_xlabel('Tempo (s)')
        axs[1,i].set_ylabel('Quantidade de Memória usada (GB)')
        axs[1,i].grid(True)
    plt.tight_layout()
    plt.show()




    # fig, ax = plt.subplots(figsize=(15, 5))

    # for i, dicionario in enumerate(memoria):
        # ax.plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024), label=f'{8*i}GB de memória de Swap')

    # ax.set_title('Gráficos do Uso da Memória')
    # ax.set_xlabel('Tempo (s)')
    # ax.set_ylabel('Quantidade de Memória (GB)')
    # ax.legend()
    # ax.autoscale()
    # ax.grid(True)

    # plt.tight_layout()
    # plt.show()


def main():
    arquivos_swap = glob.glob('*gb.txt')
    memoria = {}
    for arquivo in arquivos_swap:
        df = pd.read_table(arquivo, sep='\s+', skiprows=1 )
        nome_arquivo_sem_extensao = os.path.splitext(os.path.basename(arquivo))[0]
        memoria[nome_arquivo_sem_extensao] = df
    plot_map(memoria)

if __name__ == "__main__":
    main()

