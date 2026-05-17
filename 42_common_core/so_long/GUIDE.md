# so_long

## O que é

Criar um pequeno jogo 2D usando a biblioteca gráfica **MiniLibX**.
O jogador se move num mapa tile-based, coleta todos os itens e chega à saída.

```
./so_long maps/map01.ber
```

### Regras do jogo
- O mapa é lido de um arquivo `.ber`
- `1` = parede, `0` = espaço livre, `P` = jogador, `E` = saída, `C` = item colecionável
- O jogador precisa coletar todos os `C` antes de poder sair por `E`
- Contar e exibir o número de movimentos no terminal (ou na janela no bonus)

## Conceitos-chave

- **MiniLibX** — biblioteca X11 simplificada da 42 para janelas e renderização 2D
  - `mlx_init`, `mlx_new_window`, `mlx_loop`, `mlx_put_image_to_window`
  - `mlx_hook` — capturar eventos de teclado e fechar janela
- **XPM / PNG** — carregar texturas para tiles, jogador, inimigos
- **Parsing de mapa** — ler `.ber`, validar formato (retangular, fechado por paredes, exatamente 1 P e 1 E, ≥1 C)
- **BFS/DFS** — verificar se o mapa é válido (todos os `C` e `E` alcançáveis por `P`)
- **Tilemap rendering** — desenhar cada célula como imagem

## Como começar

1. Instalar/compilar a MiniLibX (`libmlx`)
2. Criar parser de mapa: ler arquivo, validar caracteres, checar forma retangular
3. Validar o caminho com flood fill (BFS/DFS a partir de `P`, confirmar alcance de todos `C` e `E`)
4. Renderizar o mapa: iterar sobre células, `mlx_put_image_to_window` para cada tile
5. Registrar hook de teclado (`mlx_hook` ou `mlx_key_hook`): mover jogador em W/A/S/D ou setas
6. Atualizar posição do jogador, checar coleta de itens e condição de saída

### Estrutura sugerida

```
so_long/
├── src/
│   ├── main.c         ← init mlx, janela, loop
│   ├── parse.c        ← ler e validar .ber
│   ├── validate.c     ← flood fill
│   ├── render.c       ← desenhar tiles
│   └── input.c        ← handler de teclado
├── textures/          ← arquivos .xpm ou .png
└── maps/              ← arquivos .ber de teste
```

## Funções permitidas

Funções da libft, `open`, `close`, `read`, `write`, `malloc`, `free`,
`perror`, `strerror`, `exit`, funções da MiniLibX e da biblioteca matemática.

## Referências

### MiniLibX
- [42Docs — MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Linux (repositório oficial 42)](https://github.com/42Paris/minilibx-linux)

### Artigos e tutoriais
- [Tilemap basics para jogos 2D](https://gamedevelopment.tutsplus.com/tutorials/an-introduction-to-creating-a-tile-map-engine--gamedev-10546)
- [BFS para flood fill](https://www.geeksforgeeks.org/flood-fill-algorithm/)

### Testers
- [so_long_checker (rizky-herucakra)](https://github.com/rizky-herucakra/so_long_checker)

### YouTube
- Pesquise: *"so_long 42 school MiniLibX tutorial"*
- Pesquise: *"MiniLibX 2D game 42 school"*
