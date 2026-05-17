# ft_irc

## O que é

Implementar um **servidor IRC** (Internet Relay Chat) em **C++98** compatível com clientes IRC reais (HexChat, irssi, WeeChat).

```bash
./ircserv <port> <password>
# ex: ./ircserv 6667 mysecretpass
```

O servidor deve suportar múltiplos clientes simultâneos sem travar (I/O não bloqueante com `poll()`).

## Conceitos-chave

- **TCP/IP Sockets** — `socket()`, `bind()`, `listen()`, `accept()`, `recv()`, `send()`
- **I/O Multiplexing** — `poll()` (ou `select()`/`epoll()`) para monitorar múltiplos fds sem threads
- **Protocolo IRC (RFC 1459 / RFC 2812)** — formato de mensagens, comandos, respostas numéricas
- **Parsing de mensagens IRC** — formato: `:prefix COMMAND param1 param2 :trailing\r\n`
- **Canais** — estrutura de canal: nome, tópico, lista de membros, operadores, modos
- **Modos IRC** — `i` (invite-only), `t` (tópico protegido), `k` (senha), `o` (operador), `l` (limite)

### Comandos obrigatórios

| Comando  | Descrição                              |
|----------|----------------------------------------|
| `PASS`   | Autenticação com senha do servidor     |
| `NICK`   | Definir/mudar nickname                 |
| `USER`   | Registrar usuário (username, realname) |
| `JOIN`   | Entrar em um canal                     |
| `PRIVMSG`| Enviar mensagem para canal ou usuário  |
| `KICK`   | Expulsar usuário de canal (op)         |
| `INVITE` | Convidar usuário para canal (op)       |
| `TOPIC`  | Ver/definir tópico do canal (op)       |
| `MODE`   | Alterar modos de canal ou usuário      |

## Como começar

1. Criar socket TCP, configurar `SO_REUSEADDR`, fazer `bind()` e `listen()`
2. Loop principal com `poll()`: monitorar server fd (novas conexões) + fds de clientes
3. Ao aceitar nova conexão: adicionar fd ao `pollfd[]`, criar objeto `Client`
4. Ao receber dados de um cliente: acumular no buffer até `\r\n`, parsear mensagem
5. Implementar comandos um a um (começar por PASS, NICK, USER para registro)
6. Implementar estrutura de `Channel` com mapa de membros/operadores

### Fluxo de registro de um cliente

```
cliente conecta → aguarda PASS, NICK, USER → estado: REGISTERED
→ pode usar JOIN, PRIVMSG, etc.
```

## Funções permitidas (C++98)

`socket`, `close`, `setsockopt`, `getsockname`, `getprotobyname`, `gethostbyname`,
`getaddrinfo`, `freeaddrinfo`, `bind`, `connect`, `listen`, `accept`,
`htons`, `htonl`, `ntohs`, `ntohl`, `inet_addr`, `inet_ntoa`,
`send`, `recv`, `signal`, `sigaction`, `fcntl`, `poll`

## Referências

### RFC e protocolo IRC
- [RFC 1459 — Protocolo IRC original](https://datatracker.ietf.org/doc/html/rfc1459)
- [RFC 2812 — Client Protocol atualizado](https://datatracker.ietf.org/doc/html/rfc2812)
- [IRC Numerics Reference](https://www.alien.net.au/irc/irc2numerics.html)

### Sockets e poll
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- [I/O Multiplexing com poll() — IBM](https://www.ibm.com/docs/en/i/7.4?topic=designs-using-poll-instead-select)
- `man 2 poll`, `man 2 socket`, `man 2 accept`

### Artigos
- [Construindo um servidor IRC — guia passo a passo](https://chi.cs.uchicago.edu/chirc/irc.html)

### Testers
- [42_irc_tester (rchallie)](https://github.com/rchallie/ft_irc) — referência de implementação

### YouTube
- Pesquise: *"ft_irc 42 school IRC server C++ tutorial"*
- Pesquise: *"TCP server C++ poll socket programming"*
