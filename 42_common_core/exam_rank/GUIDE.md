# exam_rank

## O que é

Avaliações práticas de programação em C realizadas no ambiente controlado da 42.
São 4 ranks obrigatórios no currículo:

| Rank | Quando                    | Dificuldade | Tempo   |
|------|---------------------------|-------------|---------|
| 02   | Após libft/get_next_line  | Iniciante   | 3 horas |
| 03   | Após ft_printf/born2beroot| Intermediário| 3 horas|
| 04   | Após minishell/philosophers| Avançado   | 3 horas |
| 05   | Após ft_irc/webserv       | Expert      | 3 horas |
| 06   | Após transcendence        | Master      | varies  |

## Rank 02 — Exercícios comuns

- `ft_putstr`, `ft_strlen`, `ft_strdup`
- `ft_strcpy`, `ft_strncpy`, `ft_strcmp`, `ft_strncmp`
- `ft_atoi`, `ft_itoa`
- `first_word`, `last_word`
- `ft_list_size`, `ft_list_push_front`
- `do_op` (calculadora simples)
- `fizzbuzz`
- `union`, `inter` (operações com strings)
- `rot13`, `rotone`
- `alpha_mirror`
- `wdmatch`

## Rank 03 — Exercícios comuns

- `get_next_line` — implementação completa
- `ft_printf` — implementação simplificada (`%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`)

## Rank 04 — Exercícios comuns

- `microshell` — implementar mini-shell com `|`, `;`, `cd`, `exec`
- `ft_printf` avançado com flags (largura, precisão, `-`, `0`, `+`, ` `, `#`)

## Rank 05 / 06 — Exercícios comuns

- Implementações mais complexas de estruturas, algoritmos ou sistemas

## Como praticar

### Ambiente do exame (reproduzir localmente)

```bash
# No exame você tem acesso a:
# - man pages
# - vim/emacs/nano
# - gcc, make
# - Nenhuma internet, nenhum código anterior

# Crie um ambiente de prática:
mkdir exam_practice && cd exam_practice
# Para cada exercício: criar função do zero, compilar, testar
```

### Método de estudo

1. Praticar cada exercício de memória (sem consultar referências)
2. Tempo: resolver cada exercício em menos de 30 minutos
3. Testar edge cases: NULL, string vazia, negativos, `INT_MIN`/`INT_MAX`
4. Usar `exam.42.fr` para prática com o sistema real

### ft_printf mínimo (Rank 03)

```c
// Formatos obrigatórios: %c %s %p %d %i %u %x %X %%
int  ft_printf(const char *format, ...);
// Usar: va_list, va_start, va_arg, va_end
// Sem buffer interno necessário — escrever direto com write()
```

### microshell (Rank 04)

```c
// Executar: cmd1 arg1 ; cmd2 | cmd3 ; cmd4
// - ';' separa sequências
// - '|' faz pipe entre comandos
// - 'cd' é builtin (sem fork)
// - Usar: execve, fork, pipe, dup2, waitpid
```

## Referências

### Plataformas de prática oficial
- [exam.42.fr](https://exam.42.fr) — sistema de exame real (treinar com sua conta 42)
- [42Exam Practice (Marchetti Nicola)](https://github.com/nicholasgasior/42-exam) — lista de exercícios comuns

### Repositórios de referência
- [exam rank 02 soluções (referência de estudo)](https://github.com/pasqualerossi/42-School-Exam-Rank-02)
- [exam rank 03 — ft_printf guia](https://github.com/pasqualerossi/42-School-Exam-Rank-03)
- [exam rank 04 — microshell explicado](https://github.com/pasqualerossi/42-School-Exam-Rank-04)

### Man pages essenciais para exames
- `man 3 va_list` (ft_printf)
- `man 2 write` (output)
- `man 2 execve`, `man 2 fork`, `man 2 pipe`, `man 2 dup2` (microshell)

### YouTube
- Pesquise: *"42 school exam rank 02 preparation"*
- Pesquise: *"ft_printf from scratch C tutorial exam 42"*
- Pesquise: *"microshell 42 exam rank 04 solution walkthrough"*
