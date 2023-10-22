#include <stdio.h>
#include <unistd.h> // Para as chamadas de sistema read e write
#include <stdlib.h>

int main() {
    int soma_ou_sub; // para decidir se vai somar ou subtrair
    int a, b, soma; // valores a serem somados

    // Mensagem de prompt
    char prompt[] = "Digite 1 para soma e 2 para subtração\n";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1); // Chamada de sistema para escrever na tela

    // Leitura da entrada
    char input_buffer[10]; // Buffer para a entrada
    int bytes_read = read(STDIN_FILENO, input_buffer, sizeof(input_buffer));
    if (bytes_read <= 0) {
        // Erro de leitura
        return 1;
    }
    input_buffer[bytes_read - 1] = '\0'; // Substituir a quebra de linha por terminador nulo
    sscanf(input_buffer, "%d", &soma_ou_sub);

    // Loop para garantir entrada válida
    while (soma_ou_sub != 1 && soma_ou_sub != 2) {
        char invalid_prompt[] = "Número inválido, digite 1 para soma e 2 para subtração:\n";
        write(STDOUT_FILENO, invalid_prompt, sizeof(invalid_prompt) - 1);

        bytes_read = read(STDIN_FILENO, input_buffer, sizeof(input_buffer));
        if (bytes_read <= 0) {
            // Erro de leitura
            return 1;
        }
        input_buffer[bytes_read - 1] = '\0'; // Substituir a quebra de linha por terminador nulo
        sscanf(input_buffer, "%d", &soma_ou_sub);
    }

    // Lógica para soma ou subtração
    if (soma_ou_sub == 1) {
        char prompt[] = "Digite os números a serem somados (separados por espaço):\n";
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
        bytes_read = read(STDIN_FILENO, input_buffer, sizeof(input_buffer));
        if (bytes_read <= 0) {
            // Erro de leitura
            return 1;
        }
        input_buffer[bytes_read - 1] = '\0'; // Substituir a quebra de linha por terminador nulo
        sscanf(input_buffer, "%d %d", &a, &b);
        soma = a + b;
        char result_prompt[50];
        snprintf(result_prompt, sizeof(result_prompt), "O valor da soma é igual a: %d\n", soma);
        write(STDOUT_FILENO, result_prompt, strlen(result_prompt));
    } 
    
    else{
        char prompt[] = "Digite os números a serem subtraidos2 (separados por espaço):\n";
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
        bytes_read = read(STDIN_FILENO, input_buffer, sizeof(input_buffer));
        if (bytes_read <= 0) {
            // Erro de leitura
            return 1;
        }
        input_buffer[bytes_read - 1] = '\0'; // Substituir a quebra de linha por terminador nulo
        sscanf(input_buffer, "%d %d", &a, &b);
        soma = a - b;
        char result_prompt[50];
        snprintf(result_prompt, sizeof(result_prompt), "O valor da subtração é igual a: %d\n", soma);
        write(STDOUT_FILENO, result_prompt, strlen(result_prompt));
    }
    exit(0);
    return 0;
}