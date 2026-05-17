# born2beroot

## O que é

Criar e configurar uma **máquina virtual** (VirtualBox ou UTM) com um servidor Linux mínimo seguindo diretrizes rígidas de segurança.
Ao final, você terá um servidor Debian/Rocky Linux funcional, seguro e auditável.

### O que configurar

- Partições LVM criptografadas (layout obrigatório)
- SSH rodando na porta `4242` (sem login root via SSH)
- Firewall UFW com apenas a porta `4242` aberta
- Política de senhas fortes (`libpam-pwquality`)
- Sudo com configurações restritas e log de comandos
- Script `monitoring.sh` exibindo status do sistema a cada 10 min via `wall`

## Conceitos-chave

- **Virtualização** — VirtualBox: criar VM, definir CPU/RAM/disco, instalar SO
- **LVM (Logical Volume Manager)** — particionamento lógico; volumes redimensionáveis
- **Criptografia de disco** — LUKS via `dm-crypt`; senha pedida no boot
- **APT / DNF** — gerenciadores de pacotes Debian / Rocky Linux
- **SSH** — protocolo de acesso remoto seguro; configurar em `/etc/ssh/sshd_config`
- **UFW (Uncomplicated Firewall)** — wrapper para iptables; simples e direto
- **sudo** — elevação de privilégios; configurar em `/etc/sudoers.d/`
- **PAM** — Pluggable Authentication Modules; políticas de senha em `/etc/security/pwquality.conf`
- **cron** — agendador de tarefas; executar `monitoring.sh` com `*/10 * * * *`

## Como começar

1. Baixar ISO do Debian (estável) ou Rocky Linux no site oficial
2. Criar VM no VirtualBox: 1 CPU, 1024MB RAM, disco 8-30GB
3. Instalar SO sem interface gráfica (apenas SSH server + utilitários base)
4. Configurar partições LVM + LUKS durante a instalação (partição `/boot` separada, resto criptografado)
5. Após instalação: configurar SSH, UFW, sudo, PAM, hostname (`login42`)
6. Escrever `monitoring.sh` com `uname`, `lscpu`, `free`, `df`, `last`, `who` etc.
7. Configurar cron para rodar o script a cada 10 minutos

### Script monitoring.sh (estrutura)

```bash
#!/bin/bash
# Arquitetura e kernel
ARCH=$(uname -a)
# CPUs físicos/virtuais
PCPU=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
VCPU=$(grep -c processor /proc/cpuinfo)
# RAM
RAM_TOTAL=$(free -m | awk '/Mem:/ {print $2}')
RAM_USED=$(free -m  | awk '/Mem:/ {print $3}')
# Disco, CPU load, ultimo boot, LVM, conexões, usuários, IP, MAC, sudo
...
wall "
    Architecture   : $ARCH
    Physical CPUs  : $PCPU
    Virtual CPUs   : $VCPU
    ...
"
```

## Referências

### Documentação oficial
- [Debian Installation Guide](https://www.debian.org/releases/stable/amd64/index.en.html)
- [LVM HOWTO (tldp.org)](https://tldp.org/HOWTO/LVM-HOWTO/)
- [UFW Documentation (Ubuntu)](https://help.ubuntu.com/community/UFW)
- [sudo manual](https://www.sudo.ws/docs/man/sudo.man/)
- `man 5 sshd_config`, `man 8 ufw`, `man 5 sudoers`

### Artigos
- [Como configurar servidor Debian seguro — DigitalOcean](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-debian-11)
- [LVM tutorial — tecmint](https://www.tecmint.com/create-lvm-storage-in-linux/)
- [PAM password policy — tutorial](https://www.server-world.info/en/note?os=Debian_11&p=pam&f=1)

### YouTube
- Pesquise: *"born2beroot 42 school guide tutorial"*
- Pesquise: *"debian LVM criptografia instalação tutorial"*
- Pesquise: *"VirtualBox Debian server setup from scratch"*
