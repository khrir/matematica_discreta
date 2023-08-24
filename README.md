# Matemática Discreta
Repositórios de código da matéria de Matemática Discreta (MD :candy:).

## :hammer_and_wrench: Ambiente de Desenvolvimento

Garanta que as seguintes ferramentas estão instaladas na sua máquina:

- [Git](https://git-scm.com/download)
- [GCC](https://gcc.gnu.org/)
- [Docker](https://docker.com)

#### 1. Tendo elas instaladas, clone o repositório:

```bash
$ git clone https://github.com/khrir/matematica_discreta.git
```

#### 2. Caso queira executar através do gcc:

- Acesse a pasta da lista: 

```bash
$ cd matematica_discreta/lista
```

- Execute o algoritmo da questão:

```bash
$ gcc <nome_questao>.c -o <nome_executavel>
$ ./<nome_executavel>
```

#### 3. Caso queira executar através do Docker:

Acesse a pasta do projeto:

```bash
$ cd matematica_discreta/
```

Modifique o arquivo imagem docker com o nome da questão:
```bash
$ nano Dockerfile
```

Execute os seguintes comandos:

```bash
$ docker build -t my-gcc-app .
$ docker run -it --rm --name my-running-app my-gcc-app
```

#### 4. Observação :loudspeaker:

- Sempre que for realizar alguma alteração no projeto, execute o git pull, de modo a evitar conflitos de commit. 
