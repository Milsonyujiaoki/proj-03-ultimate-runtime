# NetPractice

## O que é

Um exercício de **redes de computadores e subnetting** feito numa interface web interativa.
Você recebe diagramas de rede com dispositivos e endereços IP incompletos e deve preenchê-los corretamente para que a rede funcione.

```
Acesso via navegador → interface gráfica → 15 níveis de dificuldade crescente
```

Não há código a escrever — o objetivo é entender **como redes IP funcionam**.

## Conceitos-chave

### Fundamentos de IP

- **Endereço IPv4** — 4 octetos de 8 bits: `192.168.1.1`
- **Máscara de sub-rede (subnet mask)** — define a parte de rede e a parte de host
  - `255.255.255.0` = `/24` (CIDR) → 256 endereços, 254 hosts
  - `255.255.255.128` = `/25` → 128 endereços, 126 hosts
- **CIDR Notation** — `/24`, `/25`, `/26` etc.
- **Endereço de rede** — primeiro IP da sub-rede (não atribuível a host)
- **Broadcast** — último IP da sub-rede (não atribuível a host)
- **Gateway** — roteador que conecta sub-redes diferentes
- **Tabela de roteamento** — regras que definem por onde enviar pacotes

### Regras essenciais

1. Dois dispositivos na mesma sub-rede têm a mesma parte de rede
2. O gateway de uma interface deve estar na mesma sub-rede que ela
3. Sub-redes diferentes precisam de um roteador entre elas
4. `127.x.x.x` → loopback (nunca usar para rede real)
5. `0.0.0.0/0` na tabela de roteamento = rota padrão (default route)

### Operações de subnet

```
Rede: 192.168.1.0/26
Máscara: 255.255.255.192 (11000000 em binário no último octeto)
Endereços: 192.168.1.0 → 192.168.1.63
Rede: 192.168.1.0 (não atribuível)
Broadcast: 192.168.1.63 (não atribuível)
Hosts válidos: 192.168.1.1 → 192.168.1.62 (62 hosts)
```

## Como estudar

1. Aprender binário ↔ decimal para octetos (praticar conversão)
2. Entender máscaras: `/24`=254 hosts, `/25`=126, `/26`=62, `/27`=30, `/28`=14, `/29`=6, `/30`=2
3. Praticar: dado um IP e máscara, identificar: endereço de rede, broadcast, range de hosts
4. Entender tabelas de roteamento: `destination/mask → interface/next_hop`
5. Resolver os níveis em ordem; os primeiros são simples (verificar que dois hosts têm mesma sub-rede)

### Cheat sheet de máscaras

| CIDR | Máscara           | Hosts |
|------|-------------------|-------|
| /24  | 255.255.255.0     | 254   |
| /25  | 255.255.255.128   | 126   |
| /26  | 255.255.255.192   | 62    |
| /27  | 255.255.255.224   | 30    |
| /28  | 255.255.255.240   | 14    |
| /29  | 255.255.255.248   | 6     |
| /30  | 255.255.255.252   | 2     |

## Referências

### Documentação e tutoriais
- [Subnetting Made Easy — Cisco](https://www.cisco.com/c/en/us/support/docs/ip/routing-information-protocol-rip/13788-3.html)
- [CIDR Calculator online](https://www.subnet-calculator.com/)
- [IP Subnetting from CIDR — tutorial completo](https://www.digitalocean.com/community/tutorials/understanding-ip-addresses-subnets-and-cidr-notation-for-networking)
- [Tabelas de roteamento explicadas](https://www.cloudflare.com/learning/network-layer/what-is-routing/)

### RFCs
- [RFC 791 — Internet Protocol](https://datatracker.ietf.org/doc/html/rfc791)
- [RFC 4632 — CIDR](https://datatracker.ietf.org/doc/html/rfc4632)

### YouTube
- Pesquise: *"netpractice 42 school subnetting guide"*
- Pesquise: *"subnetting tutorial IPv4 CIDR explained"*
- Pesquise: *"IP addressing and subnetting for beginners"*
