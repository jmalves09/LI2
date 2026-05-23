Projeto Laboratorios de Informática II

# Motor de Jogos de Paciência em C

Projeto desenvolvido em C que implementa um motor genérico de jogos de paciência através de uma DSL.

O programa lê ficheiros `.paciencia` com as regras do jogo e permite jogar diferentes variantes de paciência no terminal.

# Funcionalidades

- Leitura de ficheiros `.paciencia`
- Criação dinâmica de pilhas
- Sistema genérico de movimentos
- Distribuição automática de cartas
- Execução de movimentos automáticos
- Sistema de ajuda
- Undo da última jogada
- Guardar jogo
- Carregar jogo
- Interface textual no terminal
- Verificação de vitória

# Estrutura do Projeto

include/
    Baralho.h
    Carta.h
    Dsl.h
    Interface.h
    Jogo.h
    Parser.h
    Pilha.h

src/
    Baralho.c
    Carta.c
    Dsl.c
    Interface.c
    Jogo.c
    Parser.c
    Pilha.c
    main.c

paciencias/
    simplesimon.paciencia
    golf.paciencia
    freecell.paciencia

saves/

Makefile
README.md

# Comandos

m origem destino - move cartas da pilha origem para pilha destino
u                - desfazer jogada (apenas 1)
h                - ajuda 
s                - guarda ficheiro (necessário dar nome, ENTER para concluir a gravação)
l                - carrega ficheiro guardado (necessario inserir nome antes, ENTER para concluir o carregamento)
q                - sair do jogo

# Save

Os jogos são guardados automaticamente na pasta saves/
Exemplo:
> s
> jogo1
cria:
saves/jogo1.txt

# RUN 

Existem 3 jogos na pasta paciencias que podem ser corridos:
freecell.paciencia
golf.paciencia
simplesimon.paciencia

para correr, escrever no terminal:
./paciencia paciencias/nome_do_ficheiro.paciencia
