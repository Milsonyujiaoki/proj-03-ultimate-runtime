# miniRT

## O que é

Implementar um **ray tracer** simples capaz de renderizar cenas 3D com iluminação.
A cena é descrita num arquivo `.rt` com câmera, luz ambiente, formas geométricas e uma luz pontual.

```
./miniRT scenes/scene.rt
```

### Formas obrigatórias
- **Esfera** (`sp`) — centro, diâmetro, cor
- **Plano** (`pl`) — ponto, vetor normal, cor
- **Cilindro** (`cy`) — centro, eixo, diâmetro, altura, cor

### Arquivo `.rt`
```
A 0.2 255,255,255        ← luz ambiente (intensidade, cor)
C -50,0,20 0,0,1 70      ← câmera (pos, direção, FOV)
L -40,0,30 0.7 255,255,255  ← luz pontual

sp 0,0,20.6 12.6 255,0,0    ← esfera
pl 0,0,0 0,1.0,0 255,0,225  ← plano
cy 50,0,20.6 0,0,1 14.2 21.42 10,0,255  ← cilindro
```

## Conceitos-chave

- **Ray casting** — lançar raio da câmera por cada pixel; testar interseção com objetos
- **Intersecção raio-esfera / raio-plano / raio-cilindro** — fórmulas algébricas (quadrática)
- **Vetor normal** — direção perpendicular à superfície no ponto de interseção
- **Modelo de iluminação de Phong** — componentes: ambiente + difuso + especular
- **Sombras** — lançar raio de sombra da interseção até a luz; checar obstáculos
- **Vetores 3D** — operações: dot product, cross product, normalização
- **Parsing** — ler e validar o arquivo `.rt`; verificar unicidade de câmera/luz ambiente

## Como começar

1. Estudar álgebra vetorial 3D (dot product, cross product, normalização)
2. Implementar as estruturas: `t_ray`, `t_camera`, `t_sphere`, `t_plane`, `t_cylinder`, `t_light`
3. Parser do `.rt`: identificar tipo de elemento por identificador, preencher structs
4. Função `cast_ray()`:
   - para cada objeto, testar interseção e registrar o mais próximo (t_min)
5. Função `shade()`:
   - calcular normal na interseção
   - calcular vetor para a luz (L)
   - componente difusa: `max(0, dot(N, L)) * light.color * object.color`
   - lançar raio de sombra; se bloqueado → sombra
6. Renderizar: para cada pixel, lançar raio primário, chamar `shade()`, escrever cor na imagem MiniLibX

### Interseção raio-esfera

```
// raio: P = O + t*D; esfera: |P - C|² = r²
// substituindo: t²(D·D) + 2t(D·(O-C)) + (O-C)·(O-C) - r² = 0
// resolver quadrática: discriminant = b²-4ac
// t_min = (-b - sqrt(discriminant)) / (2a)  se discriminant >= 0
```

## Funções permitidas

Funções da libft, `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`,
`perror`, `strerror`, `exit`, MiniLibX, `<math.h>`.

## Referências

### Ray Tracing
- [Ray Tracing in One Weekend (livro gratuito)](https://raytracing.github.io/books/RayTracingInOneWeekend.html) ← **LEITURA ESSENCIAL**
- [Scratchapixel — Ray-Sphere Intersection](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html)
- [Scratchapixel — Phong Shading Model](https://www.scratchapixel.com/lessons/3d-basic-rendering/phong-shading-reflectance-model/)

### Álgebra vetorial
- [3D Math Primer for Graphics (gratuito)](https://gamemath.com/)
- [Khan Academy — Álgebra Linear](https://pt.khanacademy.org/math/linear-algebra)

### YouTube
- Pesquise: *"miniRT 42 school ray tracer C"*
- Pesquise: *"ray tracing from scratch C tutorial"*
- [Coding a Ray Tracer — Sebastian Lague](https://www.youtube.com/watch?v=Qz0KTGYJjUsFg)
