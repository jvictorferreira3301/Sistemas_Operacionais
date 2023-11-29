import os
import time
import random

def write_sequential(file_path, file_size_mb, block_size_kb):
    with open(file_path, 'wb') as f:
        #7for _ in range(file_size_mb * 1024 // block_size_kb):
        f.write(os.urandom(1024*1024* 1024))

def read_sequential(file_path, block_size_kb):
    with open(file_path, 'rb') as f:
        while f.read(block_size_kb * 1024):
            pass

def write_random(file_path, file_size_mb, block_size_kb):
    with open(file_path, 'wb') as f:
        for _ in range(file_size_mb * 1024 // block_size_kb):
            pos = random.randint(0, file_size_mb * 1024 * 1024 - block_size_kb * 1024)
            f.seek(pos)
            f.write(os.urandom(block_size_kb * 1024))

def read_random(file_path, file_size_mb, block_size_kb):
    with open(file_path, 'rb') as f:
        for _ in range(file_size_mb * 1024 // block_size_kb):
            pos = random.randint(0, file_size_mb * 1024 * 1024 - block_size_kb * 1024)
            f.seek(pos)
            f.read(block_size_kb * 1024)

def run_tests():
    file_size_mb = 1024
    block_size_kb = 4
    num_files = 12

    for i in range(1, num_files + 1):
        file_path = f'arquivo{i}.txt'

        print(f"Running tests for {file_path}...")
        
        start_time = time.time()
        write_sequential(file_path, file_size_mb, block_size_kb)
        elapsed_time = time.time() - start_time
        print(f"Sequential Write: {elapsed_time:.2f} seconds")

        start_time = time.time()
        read_sequential(file_path, block_size_kb)
        elapsed_time = time.time() - start_time
        print(f"Sequential Read: {elapsed_time:.2f} seconds")

        start_time = time.time()
        write_random(file_path, file_size_mb, block_size_kb)
        elapsed_time = time.time() - start_time
        print(f"Random Write: {elapsed_time:.2f} seconds")

        start_time = time.time()
        read_random(file_path, file_size_mb, block_size_kb)
        elapsed_time = time.time() - start_time
        print(f"Random Read: {elapsed_time:.2f} seconds")

if __name__ == "__main__":
    run_tests()
