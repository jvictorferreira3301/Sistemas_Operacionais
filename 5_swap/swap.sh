#!/bin/bash

######################################## Primeiro teste para sem swap: ########################################
echo -e '\tTeste sem memória de Swap\n'

# Verificação se ja existe memoria de swap
if [[ $(cat /proc/swaps | wc -l) -gt 1 ]]; then
    sudo swapoff /swapfile
    sudo rm /swapfile
fi

vmstat 1 60 > swap0gb.txt &
PID=$!
sleep 10 
python3 memoria_swap.py
wait $PID
echo -e '\tTeste sem memória de Swap: Finalizado\n'

######################################## Inicio do Segundo Teste com 8gb de swap ################################
sleep 10
echo -e '\tTeste com 8gb de swap\n'

# Criação da memoria de swap

echo 'Criação da memoria de swap de 8Gb'
sudo dd if=/dev/zero of=/swapfile bs=1G count=8 &
PID=$!
wait $PID
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile

sleep 10 &
PID=$!
wait $PID
vmstat 1 60 > swap8gb.txt &
PID=$!

sleep 10 
python3 memoria_swap.py
wait $PID
echo -e '\n\tTeste com 8GB de Swap: Finalizado\n'

######################################## Inicio do Terceiro Teste com 16gb de swap ##########################
sleep 10
sudo swapoff /swapfile
sudo rm /swapfile

echo -e '\tTeste com 16gb de swap\n'

# Criação da memoria de swap

echo 'Criação da memoria de swap de 16Gb'
sudo dd if=/dev/zero of=/swapfile bs=1G count=16 &
PID=$!
wait $PID
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile

sleep 10 &
PID=$!
wait $PID
vmstat 1 60 > swap16gb.txt &
PID=$!
sleep 10

python3 memoria_swap.py
wait $PID
echo -e '\n\tTeste com 16gb de memória de Swap: Finalizada\n'
sudo chmod 666 *gb.txt


