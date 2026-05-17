# webserv

## O que é

Implementar um **servidor HTTP/1.1** em **C++98**, similar a um Nginx/Apache simplificado.
O servidor deve lidar com múltiplos clientes simultaneamente usando I/O não bloqueante.

```bash
./webserv [config_file]
./webserv config/default.conf
```

## Conceitos-chave

- **HTTP/1.1** — GET, POST, DELETE; headers, status codes, chunked transfer
- **Sockets não bloqueantes** — `fcntl(fd, F_SETFL, O_NONBLOCK)`
- **I/O Multiplexing** — `poll()` / `select()` / `epoll()` para múltiplos clients
- **Arquivo de configuração** — inspirado no Nginx: `server {}`, `location {}`, `listen`, `root`, `index`
- **CGI** — executar scripts (Python, PHP) via `fork()` + `execve()` + pipes para stdin/stdout
- **Virtual hosts** — múltiplos servidores na mesma porta via header `Host:`
- **Métodos HTTP**:
  - `GET` → servir arquivo estático
  - `POST` → receber corpo da requisição, opcionalmente executar CGI
  - `DELETE` → remover arquivo

## Como começar

1. Implementar parser do arquivo `.conf` (server blocks, location blocks)
2. Criar sockets de escuta para cada `listen` no `.conf`
3. Loop principal com `poll()`: monitorar todos os fds (listen + conexões ativas)
4. Ao aceitar conexão: criar objeto `Client`, adicionar fd ao poll
5. Ler requisição HTTP: acumular até fim dos headers (`\r\n\r\n`), ler body se `Content-Length`
6. Parsear request line + headers → decidir route com base nas `location {}` do config
7. Construir e enviar resposta: status line + headers + body

### Formato básico de uma requisição HTTP/1.1

```
GET /index.html HTTP/1.1\r\n
Host: localhost:8080\r\n
Connection: keep-alive\r\n
\r\n
```

### Configuração inspirada no Nginx

```nginx
server {
    listen 8080;
    server_name localhost;
    root /var/www/html;
    index index.html;

    location / {
        allowed_methods GET POST;
        autoindex on;
    }

    location /upload {
        allowed_methods POST DELETE;
        upload_dir /var/www/uploads;
    }

    error_page 404 /404.html;
    client_max_body_size 10M;
}
```

## Funções permitidas (C++98)

`socket`, `close`, `setsockopt`, `getsockname`, `bind`, `connect`, `listen`, `accept`,
`send`, `recv`, `fcntl`, `poll` (ou `select`/`epoll`/`kqueue`),
`htons`, `htonl`, `ntohs`, `ntohl`, `inet_addr`,
`signal`, `sigaction`, `fork`, `execve`, `dup2`, `pipe`, `waitpid`,
`open`, `read`, `write`, `stat`, `access`, `opendir`, `readdir`, `closedir`

## Referências

### HTTP/1.1
- [RFC 7230 — HTTP/1.1 Message Syntax](https://datatracker.ietf.org/doc/html/rfc7230)
- [RFC 7231 — HTTP/1.1 Semantics](https://datatracker.ietf.org/doc/html/rfc7231)
- [HTTP — MDN Web Docs](https://developer.mozilla.org/pt-BR/docs/Web/HTTP)

### Sockets e I/O
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- `man 2 poll`, `man 2 accept`, `man 2 fcntl`

### CGI
- [Common Gateway Interface — RFC 3875](https://datatracker.ietf.org/doc/html/rfc3875)
- [Como CGI funciona — tutorial](https://www.mnot.net/cgi_tools/cgi_spec.html)

### Nginx (referência de comportamento)
- [Nginx Beginner's Guide](https://nginx.org/en/docs/beginners_guide.html)

### Testers
- [webserv_tester (acuD1r)](https://github.com/acuD1r/webserv_tester) — referência

### YouTube
- Pesquise: *"webserv 42 school HTTP server C++ tutorial"*
- Pesquise: *"HTTP server from scratch C++ socket"*
- Pesquise: *"poll() non-blocking server C++ tutorial"*
