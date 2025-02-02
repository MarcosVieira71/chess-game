# Xadrez em C++ com Qt

Este projeto foi desenvolvido para um estudo de Qt, C++ e Programação Orientada a Objetos.

**Não foram implementadas** as jogadas especiais **Roque** e **En Passant**.
  
## Instalação

Para instalar as dependências e preparar o projeto para uso, basta seguir os passos abaixo:

1. Clone o repositório:
    ```bash
    git clone https://github.com/MarcosVieira71/chess-game.git
    cd chess-game
    ```

2. Execute o script `install.sh` para instalar as dependências:
    ```bash
    ./scripts/install.sh
    ```

3. Compile o projeto utilizando o script `build.sh`:
    ```bash
    ./scripts/build.sh
    ```

4. Para rodar o projeto, utilize o script `run.sh`:
    ```bash
    ./scripts/run.sh
    ```

## Estrutura do Projeto

O projeto foi estruturado utilizando o padrão **MVC** (Model-View-Controller):

- **Model(Board)**: Responsável pela lógica do jogo (movimentação das peças, regras, etc).
- **View**: Interface gráfica construída com Qt.
- **Controller**: Responsável pela interação entre o usuário e a lógica do jogo.


