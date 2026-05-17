# philosophers

## O que é

Implementar o clássico problema dos **filósofos jantando** de Dijkstra usando threads e mutexes (ou processos e semáforos no bonus).

```
./philo num_of_philosophers time_to_die time_to_eat time_to_sleep [num_times_must_eat]
./philo 5 800 200 200        → 5 filósofos, morrem se não comerem em 800ms
./philo 5 800 200 200 3      → encerra quando todos comerem 3 vezes
```

O objetivo é que nenhum filósofo morra — encontrar a sincronização correta.

## Conceitos-chave

- **Threads POSIX** — `pthread_create`, `pthread_join`, `pthread_detach`
- **Mutex** — `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`
- **Race condition** — o que acontece quando threads acessam dados compartilhados sem proteção
- **Deadlock** — quando todos os filósofos pegam o garfo da esquerda e esperam o da direita
- **Semáforo** — `sem_open`, `sem_post`, `sem_wait` (versão bonus com processos)
- **`gettimeofday()`** — medir tempo em milissegundos para verificar `time_to_die`
- **`usleep()`** — simular tempo comendo/dormindo

### Regras do problema

- N filósofos sentam numa mesa redonda
- Entre cada par de filósofos há 1 garfo (N garfos total)
- Para comer, precisa dos 2 garfos adjacentes
- Após comer, larga os garfos e dorme; depois pensa e repete
- Se passar `time_to_die` ms desde a última refeição, o filósofo morre

## Como começar

1. Criar struct para o estado global (num de filósofos, tempos, array de mutexes de garfos)
2. Criar struct por filósofo (id, ponteiro para garfos esquerdo e direito, timestamp última refeição)
3. Cada filósofo é uma thread que executa o ciclo: pensar → pegar garfos → comer → largar → dormir
4. Uma thread "monitor" verifica periodicamente se algum filósofo morreu
5. Proteger acesso ao estado compartilhado (morreu, contagem de refeições) com mutex

### Dica anti-deadlock
- Filósofos de id par pegam garfo direito primeiro; ímpares pegam esquerdo primeiro

## Funções permitidas

`pthread_create`, `pthread_detach`, `pthread_join`,
`pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`,
`gettimeofday`, `usleep`, `malloc`, `free`, `write`, `exit`
*(Bonus: `fork`, `kill`, `waitpid`, `sem_open`, `sem_post`, `sem_wait`, `sem_close`, `sem_unlink`)*

## Referências

### Man pages
- `man 7 pthreads`
- `man 3 pthread_create`
- `man 3 pthread_mutex_lock`
- `man 2 gettimeofday`
- `man 3 usleep`

### Artigos e tutoriais
- [Problema dos filósofos — Wikipedia](https://pt.wikipedia.org/wiki/Problema_do_jantar_dos_fil%C3%B3sofos)
- [POSIX Threads Tutorial (Lawrence Livermore)](https://hpc-tutorials.llnl.gov/posix/)
- [Race conditions e mutexes explicados](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)
- [Deadlock: causas e prevenção](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/)

### Testers
- [philosophers-tester (newline)](https://github.com/newline-sandbox/philosophers-tester)
- [socrates (gmarcha)](https://github.com/gmarcha/socrates)

### YouTube
- Pesquise: *"philosophers 42 school threads mutex C"*
- Pesquise: *"dining philosophers problem solution C pthreads"*
- Pesquise: *"POSIX threads tutorial C programming"*
