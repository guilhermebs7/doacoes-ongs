📦 Projeto DoeFácil – Sistema de Doações para ONGs

Projeto desenvolvido na disciplina de Estrutura de Dados Orientada a Objetos no Centro de Informática da Universidade de Pernambuco. O objetivo do trabalho é criar um sistema completo de gerenciamento de doações para Organizações Não Governamentais (ONGs), aplicando conceitos de programação orientada a objetos em C++, lógica de CRUD, persistência em banco de dados SQLite, e estrutura modular baseada em boas práticas de desenvolvimento.

🎯 Objetivo do Sistema

O sistema facilita o cadastro e a gestão de itens doados, bem como o controle de reservas e retiradas por parte das ONGs e beneficiários. Ele busca tornar o processo de doação mais transparente, organizado e rastreável, conectando doadores e instituições com uma plataforma centralizada e confiável.

🛠️ Funcionalidades

Cadastro de Usuários: Suporte para registro de Doadores e ONGs.


Login: Acesso com autenticação para gerenciamento das ações.


Doação de Itens: Doador pode cadastrar um novo item com nome, descrição, categoria e cidade.


Solicitação de Itens: ONGs podem buscar e reservar itens disponíveis.


Listagem de Usuários: Visualização de todos os doadores e ONGs registrados.


Listagem de Itens: Consulta de todos os itens com seus status (disponível, reservado, entregue).


Confirmação de Entrega: Registro da entrega de um item reservado.


Persistência via SQLite: Todas as informações são salvas em banco de dados local.


Interface por Menu: Menu interativo via terminal com todas as operações acessíveis.



📃 Estrutura do Projeto

O projeto está organizado em camadas inspiradas no padrão MVC (Model-View-Controller), com separação clara entre as responsabilidades:
graphql
CopiarEditar
📂 /
├── 📂 src/
│   ├── sistema.cpp / sistema.h          # Classe principal do sistema (Singleton)
│   ├── Ong.cpp / Ong.h                  # Classe e lógica das ONGs
│   ├── Item.h                           # Classe que representa os itens
│   ├── sqlite3.c / sqlite3.h            # Biblioteca SQLite integrada
│
├── 📄 main.cpp                          # Ponto de entrada da aplicação (menu principal)
├── 📄 doacoes_demo.db                   # Banco de dados SQLite com dados persistentes
├── 📄 DoeFácil2.exe                     # Executável compilado para Windows


🧩 Conceitos Utilizados

Programação Orientada a Objetos:
Classes como Item, Doador, Ong, Usuario e Sistema para modelagem.
Encapsulamento com atributos privados e métodos públicos.
Herança:
Classe base Usuario extendida por Doador e Ong para reutilização de código.
Polimorfismo:
Métodos como exibirPerfil() sobrescritos para comportamento específico.
Uso de vector<Usuario*> e vector<Item*> para manipulação genérica.
CRUD Completo:
Create: Cadastro de usuários e itens.
Read: Listagem de usuários e itens.
Update: Alteração de status (reserva/entrega).
Delete: Cancelamento de reservas.
Persistência com SQLite:
Dados armazenados no banco doacoes_demo.db usando a biblioteca sqlite3.
Gerenciamento Dinâmico:
Uso de ponteiros (vector<Usuario*>, vector<Item*>) para alocação dinâmica.

🧭 Fluxo Básico de Operações

Usuário acessa o menu principal via terminal.
Escolhe entre cadastrar, fazer login ou acessar funcionalidades específicas.
Doadores podem doar itens; ONGs podem buscar e reservar itens.
Todas as ações atualizam o banco de dados SQLite automaticamente.
Dados são preservados para sessões futuras.


📦 Como Executar

Para a execução correta da aplicação, é necessário ter o **SQLite** instalado.

- Baixe o SQLite para Windows (64 bits):  
  [sqlite-tools-win-x64-3500200.zip](https://www.sqlite.org/2025/sqlite-tools-win-x64-3500200.zip)

Após o download, extraia os arquivos e adicione o diretório extraído ao **Path do sistema** ou mantenha os executáveis na mesma pasta da aplicação.


✅ Pré-requisitos
Compilador C++ (g++ ou MinGW)


Sistema operacional Windows ou compatível


SQLite (incluso no projeto)


Terminal ou IDE (Visual Studio Code, CLion, etc.)


🚀 Passos
Clone o repositório:


CopiarEditar
git clone https://github.com/guilhermebs7/doacoes-ongs.git

Navegue até a pasta do projeto:


CopiarEditar
cd doacoes-ongs

Compile o projeto:


CopiarEditar
g++ -o doacoes main.cpp sistema.cpp Ong.cpp sqlite3.c

Execute o sistema:


CopiarEditar
./doacoes

Ou, caso esteja no Windows:
CopiarEditar
DoeFácil2.exe


🎓 Créditos e Autoria
Nome ; GitHub
Guilherme Barbosa <guilhermebs7>
Flavia Vitória <Flavitche>
Thiago Bernardo <codebyThiagoA>
Rodrigo Neves <rodrigoadn0>
