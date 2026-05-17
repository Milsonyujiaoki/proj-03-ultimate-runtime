# ft_transcendence

## O que é

O projeto final do currículo 42: criar uma **aplicação web full-stack** com um jogo **Pong** multiplayer online.
É desenvolvido em grupo (3-5 pessoas) e combina backend, frontend, autenticação e tempo real.

```
Funcionalidade central:
- Jogo Pong online em tempo real (browser vs browser)
- Autenticação de usuário (OAuth 42 obrigatório)
- Perfis, histórico de partidas, ranking
- Chat com canais e mensagens diretas
- Interface de usuário Single-Page Application (SPA)
```

## Componentes obrigatórios

### Backend
- **Framework**: NestJS (TypeScript) por padrão, ou outro aprovado
- API REST ou GraphQL
- Banco de dados: **PostgreSQL** via TypeORM / Prisma

### Frontend
- **SPA pura** — sem recarregamento de página
- TypeScript obrigatório
- Pode usar vanilla TS, ou framework aprovado (React, Vue, Angular)

### Jogo Pong
- Jogo em tempo real usando **WebSocket** (Socket.io ou WS nativo)
- Dois jogadores, bola, placar
- Matchmaking: fila de espera por oponente

### Autenticação e Segurança
- **OAuth 2.0 com a API da 42** (login via conta 42)
- **JWT** (JSON Web Tokens) para sessões
- **2FA** (Two-Factor Authentication) com TOTP (ex: Google Authenticator)
- Senhas hasheadas com bcrypt
- Proteção contra XSS, SQL Injection, CSRF

### Chat
- Canais: público, privado, com senha, DM
- Administração de canal (banir, mutar, kickar, tornar admin)
- Bloquear usuários

### Infraestrutura
- **Docker Compose** — tudo containerizado
- Um único `docker-compose up` sobe toda a aplicação
- Variáveis sensíveis em `.env` (nunca no repositório)

## Como começar

1. **Definir divisão do grupo**: backend, frontend, devops/infraestrutura
2. **Dockerizar** primeiro: criar `docker-compose.yml` com services `backend`, `frontend`, `db`
3. **Backend**: inicializar projeto NestJS; configurar TypeORM + PostgreSQL; criar módulo de autenticação OAuth 42
4. **Frontend**: criar SPA; implementar tela de login (botão OAuth 42)
5. **Jogo**: implementar Pong com canvas HTML5 + WebSocket; sincronizar estado entre dois clientes
6. **Chat**: implementar via WebSocket (Socket.io); criar entidades de canal, mensagem, participante

### Stack recomendada

```
Frontend  : React + TypeScript (Vite)
Backend   : NestJS (TypeScript) + Socket.io
Database  : PostgreSQL + TypeORM
Auth      : OAuth2 (42 API) + JWT + bcrypt + otplib (2FA)
Infra     : Docker Compose + nginx (reverse proxy)
```

### Exemplo de docker-compose.yml (estrutura)

```yaml
services:
  frontend:
    build: ./frontend
    ports: ["3000:3000"]
  backend:
    build: ./backend
    environment:
      DATABASE_URL: postgres://user:pass@db:5432/pong
    depends_on: [db]
  db:
    image: postgres:15-alpine
    volumes: [pg_data:/var/lib/postgresql/data]
volumes:
  pg_data:
```

## Referências

### Documentação oficial
- [NestJS — documentação](https://docs.nestjs.com/)
- [TypeORM — documentação](https://typeorm.io/)
- [Socket.io — documentação](https://socket.io/docs/v4/)
- [OAuth 2.0 — API 42](https://api.intra.42.fr/apidoc/guides/getting_started)
- [JWT — jwt.io](https://jwt.io/introduction)
- [PostgreSQL — documentação](https://www.postgresql.org/docs/)

### Segurança
- [OWASP Top 10](https://owasp.org/www-project-top-ten/)
- [bcrypt — como usar em Node.js](https://www.npmjs.com/package/bcrypt)
- [TOTP / 2FA com otplib](https://www.npmjs.com/package/otplib)

### Jogo Pong
- [HTML5 Canvas — MDN](https://developer.mozilla.org/pt-BR/docs/Web/API/Canvas_API/Tutorial)
- [WebSocket API — MDN](https://developer.mozilla.org/pt-BR/docs/Web/API/WebSockets_API)
- [Game loop em JavaScript](https://developer.mozilla.org/en-US/docs/Games/Anatomy)

### YouTube
- Pesquise: *"ft_transcendence 42 school full stack pong tutorial"*
- Pesquise: *"NestJS PostgreSQL JWT tutorial"*
- Pesquise: *"Socket.io multiplayer game tutorial"*
- Pesquise: *"OAuth2 42 API login tutorial"*
