# cub3D

## O que é

Criar um motor gráfico 3D simples inspirado no **Wolfenstein 3D** usando a técnica de **raycasting**.
A "câmera" do jogador percorre um mapa 2D e projeta paredes em perspectiva 3D.

```
./cub3D maps/map01.cub
```

### Arquivo `.cub` (mapa)
```
NO ./textures/north.xpm   ← textura da parede Norte
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0               ← cor do chão (R,G,B)
C 225,30,0                ← cor do teto

111111
100001
1N0001    ← N = posição e direção inicial do jogador
100001
111111
```

## Conceitos-chave

- **Raycasting** — lançar um raio por cada coluna de pixels; calcular distância à parede
- **DDA (Digital Differential Analysis)** — algoritmo eficiente para grid-raycasting
- **Projeção de parede** — altura da coluna inversamente proporcional à distância
- **Texturas** — mapear a textura correta (N/S/E/W) conforme face atingida pelo raio
- **MiniLibX** — renderização; imagem direta pixel a pixel
- **Parsing** — validar arquivo `.cub`: texturas, cores, mapa retangular fechado por `1`

## Como começar

1. Estudar o tutorial de raycasting do **Lode Vandevenne** (referência obrigatória)
2. Implementar o parser do `.cub` com validações completas
3. Inicializar MiniLibX, criar imagem de framebuffer
4. Loop principal: para cada coluna x de 0..W-1, lançar raio com DDA
5. Calcular altura da parede projetada, amostrar textura, escrever pixels no framebuffer
6. Enviar framebuffer para janela; capturar input (WASD + setas para mover/girar)

### Algoritmo DDA (simplificado)

```
Para cada coluna x:
  → calcular direção do raio com base no ângulo da câmera
  → DDA: avançar no grid até bater numa parede (cellMap == '1')
  → calcular distância perpendicular (evitar efeito fish-eye)
  → altura da linha = H / distPerp
  → amostrar pixel da textura (coordenada u baseada no offset na parede)
  → desenhar linha vertical de teto, parede texturizada, chão
```

## Funções permitidas

Funções da libft, `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`,
`perror`, `strerror`, `exit`, MiniLibX, `<math.h>`.

## Referências

### Raycasting (ESSENCIAL)
- [Lode's Raycasting Tutorial — Parte 1](https://lodev.org/cgtutor/raycasting.html)
- [Lode's Raycasting Tutorial — Parte 2 (texturas)](https://lodev.org/cgtutor/raycasting2.html)
- [Lode's Raycasting Tutorial — Partes 3 e 4](https://lodev.org/cgtutor/raycasting3.html)

### MiniLibX
- [42Docs — MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [42Docs — cub3D](https://harm-smits.github.io/42docs/projects/cub3d.html)

### Artigos complementares
- [Algoritmo DDA explicado](https://www.geeksforgeeks.org/dda-line-generation-algorithm-computer-graphics/)
- [Fixing fish-eye effect in raycasting](https://permadi.com/1996/05/ray-casting-tutorial-8/)

### YouTube
- Pesquise: *"cub3d 42 school raycasting tutorial"*
- Pesquise: *"raycasting C tutorial Wolfenstein engine"*
- [3D game from scratch (raycasting) — OneLoneCoder](https://www.youtube.com/watch?v=NbSee-XM7WA)
