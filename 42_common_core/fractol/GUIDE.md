# fract-ol

## O que é

Renderizar fractais matemáticos de forma interativa usando a **MiniLibX**.
O usuário pode navegar (zoom + pan) pelos fractais em tempo real.

```
./fractol mandelbrot
./fractol julia <Re> <Im>    # ex: ./fractol julia -0.7 0.27015
./fractol burning_ship        # bonus
```

### Fractais obrigatórios
- **Mandelbrot** — o fractal clássico: z = z² + c, c ∈ ℂ
- **Julia** — mesma fórmula, c é fixo e z varia; parâmetro passado pelo usuário

## Conceitos-chave

- **Números complexos** — parte real e imaginária: `z = a + bi`
- **Iteração de escape** — contar quantas iterações até |z| > 2 (ou limite máximo)
- **Mapeamento de pixels** — cada pixel corresponde a um ponto do plano complexo
- **Colorização** — mapear contagem de iterações para cor (gradiente suave ou paleta)
- **MiniLibX** — renderização pixel a pixel com `mlx_pixel_put` ou escrita direta em imagem
- **Zoom** — scroll do mouse → re-escalar o intervalo [Re_min, Re_max] × [Im_min, Im_max]
- **Panning** — arrastar ou teclas de seta → transladar o centro da view

## Como começar

1. Abrir janela MiniLibX, criar imagem (`mlx_new_image`)
2. Para cada pixel (px, py), mapear para (Re, Im) no plano complexo
3. Iterar a fórmula do fractal; contar iterações até escape ou MAX_ITER
4. Colorir o pixel com base na contagem; escrever na imagem
5. Enviar imagem para a janela (`mlx_put_image_to_window`)
6. Registrar hooks: scroll → zoom, teclas → pan, ESC → fechar

### Mapeamento pixel → complexo

```c
// janela WxH, view [re_min, re_max] × [im_min, im_max]
double re = re_min + (double)px / W * (re_max - re_min);
double im = im_min + (double)py / H * (im_max - im_min);
```

### Fórmula Mandelbrot

```c
// z0 = 0; c = re + i*im
double zr = 0, zi = 0, tmp;
int iter = 0;
while (zr*zr + zi*zi <= 4.0 && iter < MAX_ITER) {
    tmp = zr*zr - zi*zi + re;   // parte real de z² + c
    zi  = 2.0 * zr * zi  + im;  // parte imaginária
    zr  = tmp;
    iter++;
}
```

## Funções permitidas

Funções da libft, `open`, `close`, `read`, `write`, `malloc`, `free`,
`perror`, `strerror`, `exit`, MiniLibX, `<math.h>`.

## Referências

### Matemática dos fractais
- [Conjunto de Mandelbrot — Wikipedia PT](https://pt.wikipedia.org/wiki/Conjunto_de_Mandelbrot)
- [Conjunto de Julia — Wikipedia PT](https://pt.wikipedia.org/wiki/Conjunto_de_Julia)
- [Smooth coloring (continuação de bandas)](https://iquilezles.org/articles/mset_smooth/)

### MiniLibX
- [42Docs — MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

### Artigos visuais
- [Fractals e colorização (Inigo Quilez)](https://iquilezles.org/articles/)
- [How to render Mandelbrot in C — tutorial](https://www.youtube.com/results?search_query=mandelbrot+set+C+render)

### Testers / Referências visuais
- [fract-ol-checker](https://github.com/wwatkins42/fract-ol) — referência visual

### YouTube
- Pesquise: *"fract-ol 42 school fractals C MiniLibX"*
- Pesquise: *"mandelbrot set C implementation tutorial"*
- Pesquise: *"fractals zoom C programming"*
