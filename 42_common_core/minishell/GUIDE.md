# minishell

## O que é

Implementar um shell simples similar ao **bash**, capaz de executar comandos, lidar com pipes, redirecionamentos e variáveis de ambiente.

```bash
$ ./minishell
minishell$ ls -la | grep .c > output.txt
minishell$ echo $HOME
minishell$ export MY_VAR=hello
minishell$ exit
```

## Conceitos-chave

- **Lexer (tokenização)** — dividir a linha de input em tokens: palavras, `|`, `>`, `<`, `>>`, `<<`, variáveis `$`
- **Parser (AST)** — construir uma árvore de comandos a partir dos tokens
- **Expansão de variáveis** — `$VAR` → valor de `getenv("VAR")`; `$?` → exit status anterior
- **Redirections** — `>` (truncar), `>>` (append), `<` (stdin), `<<` (heredoc)
- **Pipes** — `cmd1 | cmd2` → `pipe()` + `fork()` + `execve()`
- **Builtins** — implementar internamente: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Signals** — `SIGINT` (Ctrl+C) → nova linha; `SIGQUIT` (Ctrl+\`) → ignorar; em child → comportamento padrão
- **`readline()`** — ler input com histórico e edição de linha
- **`execve()`** — executar comandos externos procurando no PATH

## Como começar

1. Configurar readline; loop principal: `readline()` → `add_history()` → processar → repetir
2. Implementar lexer: varrer a string char a char, identificar tokens com tipo e valor
3. Implementar parser: tokens → lista de comandos (cmd + args + redirections)
4. Executar: para um comando simples, `fork()` + `execve()`; para pipes, encadear com `pipe()` + múltiplos `fork()`
5. Implementar builtins antes de tentar `execve()`
6. Tratar signals com `sigaction` no processo principal

### Estrutura sugerida do pipeline

```
input → [Lexer] → tokens → [Parser] → cmd_list → [Executor] → processos
```

### Builtins obrigatórios

| Builtin  | Comportamento                                     |
|----------|---------------------------------------------------|
| `echo`   | `-n` não imprime newline                          |
| `cd`     | muda diretório; atualiza `PWD` e `OLDPWD`         |
| `pwd`    | imprime diretório atual                           |
| `export` | adiciona/atualiza variável no ambiente            |
| `unset`  | remove variável do ambiente                       |
| `env`    | lista variáveis de ambiente                       |
| `exit`   | encerra o shell com código de saída               |

## Funções permitidas

`readline`, `add_history`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`,
`printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`,
`fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`,
`kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`,
`execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`,
`strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`,
`getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

## Referências

### Bash Reference
- [Bash Manual — GNU](https://www.gnu.org/software/bash/manual/bash.html)
- [Shell Grammar — POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

### Artigos e tutoriais
- [Writing a Shell in C — Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Building a shell — tutorial detalhado](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [Readline Library docs (GNU)](https://tiswww.case.edu/php/chet/readline/rltop.html)

### Testers
- [minishell_tester (LucasKuhn)](https://github.com/LucasKuhn/minishell_tester)
- [42_minishell_tester (zstenger)](https://github.com/zstenger93/42_minishell_tester)

### YouTube
- Pesquise: *"minishell 42 school shell implementation C"*
- Pesquise: *"write a shell in C tutorial"*
- Pesquise: *"lexer parser AST shell C programming"*
