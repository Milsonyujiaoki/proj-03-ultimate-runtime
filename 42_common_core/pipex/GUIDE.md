# pipex

## O que é

Replicar o comportamento do pipe shell:

```bash
< infile cmd1 | cmd2 > outfile
# equivalente a:
./pipex infile cmd1 cmd2 outfile
```

O projeto exercita **`fork`**, **`pipe`** e **`execve`** — os pilares de processos UNIX.

## Conceitos-chave

- **`pipe()`** — criar par de fds (leitura/escrita) para comunicação entre processos
- **`fork()`** — criar processo filho; retorna PID ao pai, 0 ao filho
- **`execve()`** — substituir imagem do processo por um novo executável
- **`dup2()`** — redirecionar stdin/stdout para os extremos do pipe ou para arquivos
- **`wait()` / `waitpid()`** — pai aguarda filhos terminarem e coleta exit status
- **`open()` / `close()`** — abrir `infile` e `outfile` com flags corretas
- **`PATH`** — percorrer variável de ambiente para encontrar executável de `cmd`

## Como começar

1. Abrir `infile` (leitura) e `outfile` (escrita/criação/truncar)
2. Criar o pipe com `pipe(fd)`
3. `fork()` → filho 1:
   - `dup2(infile, STDIN_FILENO)` → redireciona entrada
   - `dup2(fd[1], STDOUT_FILENO)` → escreve no pipe
   - fechar fds desnecessários, `execve(cmd1, ...)`
4. `fork()` → filho 2:
   - `dup2(fd[0], STDIN_FILENO)` → lê do pipe
   - `dup2(outfile, STDOUT_FILENO)` → escreve na saída
   - fechar fds desnecessários, `execve(cmd2, ...)`
5. Pai fecha todos os fds, `waitpid()` ambos os filhos

### Bonus
- Múltiplos pipes: `./pipex infile cmd1 cmd2 cmd3 ... outfile`
- Here-doc: `./pipex here_doc LIMITER cmd1 cmd2 outfile` (usa `<<`)

## Funções permitidas

`open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`,
`access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`,
`wait`, `waitpid`

## Referências

### Man pages
- `man 2 pipe`
- `man 2 fork`
- `man 2 execve`
- `man 2 dup2`
- `man 2 waitpid`

### Artigos e tutoriais
- [Beej's Guide — Pipes](https://beej.us/guide/bgipc/html/split/pipes.html)
- [Fork, Exec, Wait — tutorial](https://www.bogotobogo.com/Linux/linux_process_and_fork_exec.php)
- [Como funciona o pipe no shell](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_02)

### Testers
- [pipex-tester (vfurmane)](https://github.com/vfurmane/pipex-tester)
- [pipexMedic (gmarcha)](https://github.com/gmarcha/pipexMedic)

### YouTube
- Pesquise: *"pipex 42 school fork pipe execve"*
- Pesquise: *"Unix inter-process communication pipe fork C"*
