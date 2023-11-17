import time
import random 

file_size_gb = 1
num_files = 12

# Criar arquivos de 1GB cada
for i in range(num_files):
    filename = f"file_{i}.txt"
    with open(filename, 'w') as file:
        # Preencher o arquivo com o texto 'oie tudo bem?' até atingir 1GB
        file.write('oie tudo bem?' * (file_size_gb * 1024 * 1024 * 1024 // len('oie tudo bem?')))

def read_sequential():
    start_time = time.time()
    for i in range(num_files):
        filename = f"file_{i}.txt"
        with open(filename, 'r') as file:
            while True:
                data = file.read(1024)  # Leia blocos de 1KB
                if not data:
                    break
    end_time = time.time()
    return end_time - start_time

def write_sequential():
    start_time = time.time()
    for i in range(num_files):
        filename = f"file_{i}.txt"
        with open(filename, 'w') as file:
            file.write('oie tudo bem?' * (file_size_gb * 1024 * 1024 * 1024 // len('oie tudo bem?')))

    end_time = time.time()
    return end_time - start_time

def read_random():
    start_time = time.time()
    for i in range(num_files):
        filename = f"file_{i}.txt"
        with open(filename, 'r') as file:
            file.seek(random.randint(0, file_size_gb * 1024 * 1024 * 1024))  # Posiciona aleatoriamente
            data = file.read(1024)  # Lê blocos de 1KB
    end_time = time.time()
    return end_time - start_time

def write_random():
    start_time = time.time()
    for i in range(num_files):
        filename = f"file_{i}.txt"
        with open(filename, 'r+') as file:
            file.seek(random.randint(0, file_size_gb * 1024 * 1024 * 1024))  # Posiciona aleatoriamente
            file.write('oie tudo bem?' * (file_size_gb * 1024 * 1024 * 1024 // len('oie tudo bem?')))
    end_time = time.time()
    return end_time - start_time
sequential_read_time = read_sequential()
sequential_write_time = write_sequential()
random_read = read_random()
random_write = write_random()

print(f"Tempo de leitura sequencial: {sequential_read_time} segundos")
print(f"Tempo de escrita sequencial: {sequential_write_time} segundos")
print(f"Tempo de leitura aleatoria: {random_read} segundos")
print(f"Tempo de escrita aleatoria: {random_write} segundos")

