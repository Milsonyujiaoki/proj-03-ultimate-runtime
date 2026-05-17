# push_swap

## O que é

Ordenar uma pilha de inteiros usando o **menor número possível de operações**, com apenas duas pilhas (`a` e `b`) e um conjunto limitado de instruções.

```bash
./push_swap 5 1 3 2 4     → imprime a sequência de operações
./checker 5 1 3 2 4       # bonus: validar se sequência ordena a pilha
```

### Operações disponíveis

| Instrução | Descrição                                            |
|-----------|------------------------------------------------------|
| `sa`      | swap dos 2 primeiros elementos de a                  |
| `sb`      | swap dos 2 primeiros elementos de b                  |
| `ss`      | `sa` e `sb` simultaneamente                          |
| `pa`      | push do topo de b para a                             |
| `pb`      | push do topo de a para b                             |
| `ra`      | rotate a: primeiro elemento vai para o final         |
| `rb`      | rotate b                                             |
| `rr`      | `ra` e `rb` simultaneamente                          |
| `rra`     | reverse rotate a: último elemento vai para o topo    |
| `rrb`     | reverse rotate b                                     |
| `rrr`     | `rra` e `rrb` simultaneamente                        |

### Limites de operações (avaliação)

| Tamanho | Nota máxima sem erros |
|---------|-----------------------|
| 3 nºs   | ≤ 3 ops (100%)        |
| 5 nºs   | ≤ 12 ops (100%)       |
| 100 nºs | ≤ 700 ops (100%)      |
| 500 nºs | ≤ 5500 ops (100%)     |

## Conceitos-chave

- **Pilha (stack)** — estrutura LIFO; operações apenas no topo/fundo
- **Algoritmo de ordenação eficiente** — para n pequeno: hardcode; para n grande: algoritmo otimizado
- **Compressão de índices** — converter valores para índices 0..n-1 (simplifica comparações)
- **Algoritmo turk (radix sort / insertion + pivot)** — estratégia popular para 100/500 elementos
- **Cost analysis** — para cada elemento em b, calcular custo de inseri-lo em a na posição correta

## Como começar

1. Parsear argumentos; validar (sem duplicatas, apenas inteiros, dentro de `INT_MIN..INT_MAX`)
2. Implementar as 11 operações como funções que manipulam duas listas/arrays
3. Caso especial `n=2`: se `a[0] > a[1]`, `sa`
4. Caso especial `n=3`: resolver em ≤3 operações (6 casos possíveis)
5. Para `n≤5`: estender o caso de 3 fazendo `pb` para reduzir a 3 elements
6. Para `n>5` — **algoritmo Turkish sort (inserção otimizada)**:
   - Empurrar tudo para `b` (exceto 2-3 maiores em `a`)
   - Para cada elemento de `b`, calcular custo de inserir no lugar certo de `a`
   - Inserir o elemento de menor custo
   - Repetir até `b` vazio; ajustar `ra`/`rra` para colocar mínimo no topo

## Referências

### Algoritmos
- [Turkish sort / algoritmo de push_swap explicado (medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Radix sort para push_swap](https://www.geeksforgeeks.org/radix-sort/)
- [Análise de custo de inserção](https://github.com/o-reo/push_swap_visualizer)

### Visualizador
- [push_swap_visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer) — ver animação das operações

### Testers
- [push_swap_tester (laisarena)](https://github.com/laisarena/push_swap_tester)
- [push_swap_checker_Mac (o-reo)](https://github.com/o-reo/push_swap_tester)

### YouTube
- Pesquise: *"push_swap 42 school algorithm tutorial"*
- Pesquise: *"push swap algorithm sort two stacks"*
- Pesquise: *"Turkish sort push_swap explained"*
