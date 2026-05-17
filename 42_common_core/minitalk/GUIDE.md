# minitalk

## O que é

Criar um sistema de comunicação entre dois processos usando **apenas sinais UNIX**.
O projeto consiste em dois executáveis: `server` e `client`.
O cliente envia uma string ao servidor enviando os bits um a um via sinais `SIGUSR1` e `SIGUSR2`.

```
./server          → exibe o PID e fica aguardando mensagens
./client <PID> <mensagem>  → envia a mensagem bit a bit ao servidor
```

## Conceitos-chave

- **Sinais UNIX** — `SIGUSR1`, `SIGUSR2`, `SIGINT`, `SIGTERM`
- **`sigaction()`** — registrar handlers de sinal de forma confiável
- **`kill()`** — enviar sinal a um processo pelo PID
- **Representação binária** — cada caractere é enviado bit a bit (8 bits por char)
- **Sincronização** — cliente aguarda confirmação do servidor antes de enviar próximo bit (bonus)
- **`getpid()`** — obter o PID do processo atual

## Como começar

1. Criar `server.c` que registra handler para `SIGUSR1`/`SIGUSR2` e imprime seu PID
2. Criar `client.c` que recebe PID e string como argumento
3. Para cada caractere da string, iterar sobre os 8 bits
4. Enviar `SIGUSR1` para bit `0` e `SIGUSR2` para bit `1`
5. No servidor, reconstruir o caractere ao receber 8 bits, imprimir quando completo
6. Bonus: servidor confirma recebimento enviando sinal de volta ao cliente

### Codificação de um char

```c
// no cliente: enviar cada bit de 'c' do MSB ao LSB
for (int bit = 7; bit >= 0; bit--)
{
    if ((c >> bit) & 1)
        kill(server_pid, SIGUSR2);  // bit 1
    else
        kill(server_pid, SIGUSR1);  // bit 0
    usleep(100);  // aguardar processamento
}
```

## Funções permitidas

`signal`, `sigaction`, `kill`, `getpid`, `pause`, `sleep`, `usleep`,
`malloc`, `free`, `write`, `exit`

## Referências

### Man pages
- `man 2 sigaction`
- `man 2 kill`
- `man 2 getpid`
- `man 7 signal`
- `man 3 usleep`

### Artigos e tutoriais
- [Signals in C — beej's guide (seção de sinais)](https://beej.us/guide/bgc/html/split/signal-handling.html)
- [sigaction vs signal (StackOverflow)](https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal)
- [Bit manipulation em C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

### Testers
- [minitalk-tester (ThibaultVlacich)](https://github.com/ThibaultVlacich/minitalk-tester)

### YouTube
- Pesquise: *"minitalk 42 school signals C tutorial"*
- Pesquise: *"Unix signals C programming SIGUSR1 SIGUSR2"*
