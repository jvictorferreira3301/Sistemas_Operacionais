import matplotlib.pyplot as plt
import numpy as np

def plot_all_together(sequential_write_times, sequential_read_times, random_write_times, random_read_times):
    file_numbers = np.arange(1, 13)
    width = 0.2  # Largura das barras

    plt.figure(figsize=(14, 8))

    # Sequential Write
    plt.bar(file_numbers - 1.5*width, sequential_write_times, width, label='Escrita Sequencial', color='blue')

    # Sequential Read
    plt.bar(file_numbers - 0.5*width, sequential_read_times, width, label='Leitura Sequencial', color='green')

    # Random Write
    plt.bar(file_numbers + 0.5*width, random_write_times, width, label='Escrita Aleatória', color='red')

    # Random Read
    plt.bar(file_numbers + 1.5*width, random_read_times, width, label='Leitura Aleatória', color='purple')

    plt.xlabel('Arquivos')
    plt.ylabel('Tempo (segundos)')
    plt.title('Comparação entre os cenários de Benchmark')
    plt.xticks(file_numbers, file_numbers)
    plt.legend()

    plt.show()

def main():
    # Tempos fornecidos
    sequential_write_times = [3.78, 3.83, 3.84, 3.89, 5.60, 3.78, 4.47, 3.85, 3.79, 3.74, 4.41, 3.93]
    sequential_read_times = [1.03, 0.27, 0.30, 0.28, 0.92, 2.85, 0.32, 2.77, 0.27, 10.79, 5.73, 6.96]
    random_write_times = [8.84, 9.19, 9.85, 9.58, 9.28, 8.28, 10.62, 8.95, 12.84, 11.59, 14.69, 12.52]
    random_read_times = [0.71, 0.71, 0.73, 0.71, 0.75, 0.72, 0.72, 0.75, 0.71, 0.71, 0.70, 0.71]

    plot_all_together(sequential_write_times, sequential_read_times, random_write_times, random_read_times)

if __name__ == "__main__":
    main()
