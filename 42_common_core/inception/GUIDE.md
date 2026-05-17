# inception

## O que é

Configurar uma infraestrutura de serviços usando **Docker Compose**.
Cada serviço roda em seu próprio container, construído a partir de um `Dockerfile` próprio (sem usar imagens prontas do DockerHub para os serviços principais).

### Serviços obrigatórios

```
NGINX ──────── WordPress ──────── MariaDB
  (HTTPS/443)   (PHP-FPM)        (banco de dados)
                     ↕
              Volume persistente
              (wp-content, db)
```

- **NGINX** — reverse proxy com TLSv1.2/1.3 (certificado auto-assinado), porta 443
- **WordPress** + **PHP-FPM** — CMS; se comunicar com MariaDB
- **MariaDB** — banco de dados MySQL; dados persistidos em volume Docker

## Conceitos-chave

- **Container** — processo isolado com seu próprio filesystem, rede e namespace
- **Dockerfile** — instruções para construir uma imagem customizada
- **docker-compose.yml** — orquestrar múltiplos containers (redes, volumes, dependências)
- **Volume** — persistência de dados além do ciclo de vida do container
- **Network** — containers se comunicam pelo nome do serviço (DNS interno Docker)
- **PHP-FPM** — FastCGI Process Manager; NGINX delega arquivos `.php` ao PHP-FPM via socket Unix ou porta 9000
- **Variáveis de ambiente** — senhas e configs via `.env` (nunca hardcoded)
- **TLS/SSL** — gerar certificado com `openssl req -x509 ...`

## Como começar

1. Instalar Docker e Docker Compose
2. Criar `srcs/docker-compose.yml` com os 3 serviços
3. Para cada serviço, criar `Dockerfile` baseado em `debian:bullseye` ou `alpine`
4. Começar pelo MariaDB: criar script de init SQL (criar banco, usuário, senhas via `.env`)
5. Configurar WordPress: instalar `php-fpm`, usar `wp-cli` para setup inicial
6. Configurar NGINX: gerar certificado TLS, configurar `server {}` com `ssl` e `fastcgi_pass`
7. Definir volumes em `/home/<login>/data/` para persistência

### Estrutura de diretórios

```
inception/
├── Makefile               ← docker-compose up/down/clean
├── srcs/
│   ├── .env               ← variáveis de ambiente (não commitar senhas reais)
│   ├── docker-compose.yml
│   └── requirements/
│       ├── nginx/
│       │   ├── Dockerfile
│       │   └── conf/nginx.conf
│       ├── wordpress/
│       │   ├── Dockerfile
│       │   └── conf/www.conf
│       └── mariadb/
│           ├── Dockerfile
│           └── conf/init.sql
```

### Arquivo `.env` (exemplo)

```env
DOMAIN_NAME=login.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=wp_user
MYSQL_PASSWORD=wp_password
MYSQL_ROOT_PASSWORD=root_password
WP_ADMIN_USER=admin
WP_ADMIN_PASSWORD=adminpass
WP_ADMIN_EMAIL=admin@login.42.fr
```

## Referências

### Docker
- [Docker — Get Started (documentação oficial)](https://docs.docker.com/get-started/)
- [Docker Compose — documentação oficial](https://docs.docker.com/compose/)
- [Dockerfile reference](https://docs.docker.com/reference/dockerfile/)
- `man docker-compose`

### NGINX + PHP-FPM
- [NGINX + PHP-FPM — tutorial](https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mariadb-php-lemp-stack-on-debian-10)
- [NGINX TLS/SSL configuration](https://nginx.org/en/docs/http/configuring_https_servers.html)

### WordPress
- [WP-CLI — instalar WordPress pela linha de comando](https://wp-cli.org/)
- [PHP-FPM configuration](https://www.php.net/manual/en/install.fpm.configuration.php)

### MariaDB
- [MariaDB init scripts via Docker](https://mariadb.com/kb/en/docker-and-mariadb/)

### YouTube
- Pesquise: *"inception 42 school Docker Compose tutorial"*
- Pesquise: *"Docker Compose NGINX WordPress MariaDB from scratch"*
- Pesquise: *"Dockerfile tutorial debian alpine"*
