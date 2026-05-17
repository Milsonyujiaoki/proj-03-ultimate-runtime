# cpp_modules

## O que é

Uma série de **10 módulos** (00 a 09) que introduzem progressivamente os conceitos de **C++98**.
Cada módulo tem 2-5 exercícios práticos com regras e proibições claras.

```
cpp_modules/
├── cpp00/    ← Namespaces, classes, funções membro, stdio streams
├── cpp01/    ← Memória, ponteiros para membro, referências, switch
├── cpp02/    ← Forma canônica ortodoxa, sobrecarga de operadores, ponto fixo
├── cpp03/    ← Herança
├── cpp04/    ← Subtyping polimorfism, classes abstratas, interfaces
├── cpp05/    ← Try/catch, exceções
├── cpp06/    ← Casts C++
├── cpp07/    ← Templates
├── cpp08/    ← Containers e iteradores STL
└── cpp09/    ← STL avançado (mais algoritmos/containers)
```

## Regras gerais

- C++98 apenas (sem `auto`, `nullptr`, `range-for`, lambdas do C++11+)
- Sem funções C (`printf`, `malloc`, `free`) — usar `cout`, `new`, `delete`
- Sem vazamento de memória — `new` → deve ter `delete` correspondente
- Forma Canônica Ortodoxa (módulos 02+): construtor default, destrutor, construtor de cópia, operador de atribuição `=`

## Módulo por módulo

### cpp00 — Fundamentos
- Classes e objetos: atributos e métodos
- `public` / `private` / `protected`
- Construtores e destrutor
- `std::cout`, `std::cin`, `std::string`

### cpp01 — Memória e referências
- `new` / `delete` (heap vs stack)
- Referências (`int &ref = var`)
- Ponteiros para membro (`&MyClass::method`)
- Fluxo `switch`

### cpp02 — Sobrecarga e forma canônica
- **Forma Canônica Ortodoxa** — 4 funções obrigatórias
- `operator+`, `operator-`, `operator<<` (sobrecarga de operadores)
- Classe de ponto fixo (Fixed Point Number)

### cpp03 — Herança
- Herança simples e múltipla
- Resolução de ambiguidade
- Herança virtual (diamond problem)

### cpp04 — Polimorfismo
- Funções virtuais (`virtual`)
- Destrutor virtual (essencial para delete via ponteiro base)
- Classes puramente abstratas (interfaces): `virtual void fn() = 0;`
- Não usar interfaces STL

### cpp05 — Exceções
- `try` / `catch` / `throw`
- Herdar de `std::exception`; sobrescrever `what()`
- Exceções em construtores

### cpp06 — Casts
- `static_cast<T>()`
- `dynamic_cast<T>()` (RTTI; requer ao menos uma virtual)
- `reinterpret_cast<T>()`
- `const_cast<T>()`

### cpp07 — Templates
- Function templates (`template <typename T>`)
- Class templates
- Especialização de templates

### cpp08 — Containers STL
- `std::vector`, `std::list`, `std::map`, `std::set`
- Iteradores: `begin()`, `end()`, `iterator`, `const_iterator`
- Algoritmos: `std::find`, `std::find_if`, `std::count`

### cpp09 — STL avançado
- `std::stack`, `std::queue`, `std::deque`
- `std::map` avançado
- Algoritmos de ordenação e busca

## Como começar

1. Começar pelo `cpp00`: criar uma classe simples `PhoneBook` com arrays de `Contact`
2. Estudar a **forma canônica ortodoxa** antes do módulo 02 — será exigida em todos depois
3. Para cada módulo, ler o subject PDF completamente antes de começar
4. Compilar com: `c++ -Wall -Wextra -Werror -std=c++98`

### Forma Canônica Ortodoxa

```cpp
class MyClass {
public:
    MyClass();                         // construtor default
    MyClass(const MyClass &other);     // construtor de cópia
    MyClass &operator=(const MyClass &other); // operador de atribuição
    ~MyClass();                        // destrutor
};
```

## Referências

### C++98 Reference
- [cppreference.com — C++98](https://en.cppreference.com/w/cpp) — documentação completa
- [cplusplus.com — tutoriais](https://cplusplus.com/doc/tutorial/)
- [C++ Programming Language — Bjarne Stroustrup (livro)](https://www.stroustrupFaq.org/)

### Artigos específicos
- [Forma Canônica Ortodoxa explicada](https://www.learncpp.com/cpp-tutorial/the-rule-of-three/)
- [Herança virtual em C++ (diamond)](https://www.geeksforgeeks.org/virtual-base-class-in-c/)
- [Templates em C++ — tutorial](https://www.geeksforgeeks.org/templates-cpp/)
- [Exceções em C++](https://www.geeksforgeeks.org/exception-handling-c/)

### YouTube
- Pesquise: *"cpp modules 42 school C++ tutorial"*
- Pesquise: *"C++ OOP classes inheritance polymorphism"*
- [The Cherno — C++ series (YouTube)](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)
