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
    cores = ['blue', 'green', 'red']

    plt.rcParams.update({'font.size': 12})
    for i, plot in enumerate(memoria):
        plt.figure(figsize=(15, 10))
        plt.plot(-memoria[plot]['livre'] + (7.62 * 1024 * 1024), label=f'{8*i}GB de memória de Swap', linewidth=2, color=cores[i % len(cores)])
        plt.title(f'Uso da Memória com {8*i}GB de memória de Swap')
        plt.xlabel('Tempo (s)')
        plt.ylabel('Quantidade de Memória Usada (GB)')
        plt.grid(True)
        plt.xticks(range(0, 61, 5))
        plt.legend()
        plt.ylim(0,8*1024*1024)
        plt.savefig(f'{8*i}gb_swap', dpi = 350) 
        # plt.show()
    
    fig, ax = plt.subplots(figsize=(15, 10))

    for i, dicionario in enumerate(memoria):
        ax.plot(-memoria[dicionario]['livre'] + (7.62 * 1024 * 1024), label=f'{8*i}GB de memória de Swap', linewidth=2, color=cores[i % len(cores)])

    ax.set_title('Uso da Memória com configurações de Swap distintas')
    ax.set_xlabel('Tempo (s)')
    ax.set_ylabel('Quantidade de Memória Usada(GB)')
    ax.legend()
    ax.autoscale()
    ax.grid(True)
    ax.set_ylim(0,8*1024*1024)
    plt.tight_layout()
    plt.savefig('Comparacao_memoria_testes.png', dpi = 350) 
    # plt.show()

def main():
    arquivos_swap = reversed(glob.glob('*gb.txt'))
    memoria = {}
    for arquivo in arquivos_swap:
        df = pd.read_table(arquivo, sep='\s+', skiprows=1 )
        nome_arquivo_sem_extensao = os.path.splitext(os.path.basename(arquivo))[0]
        memoria[nome_arquivo_sem_extensao] = df
    plot_map(memoria)

if __name__ == "__main__":
    main()

