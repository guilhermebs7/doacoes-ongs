# 📦 DoeFácil
## Sistema de Gerenciamento de Doações para ONGs

Projeto desenvolvido na disciplina de **Estrutura de Dados Orientada a Objetos** no  
**Centro de Informática da Universidade de Pernambuco (CIn/UPE)**.

Sistema para cadastro, gerenciamento e rastreamento de doações entre **doadores** e **ONGs**, utilizando **C++**, **POO**, **CRUD** e **SQLite**.

---

## 🎯 OBJETIVO DO SISTEMA

- Facilitar o cadastro e a gestão de itens doados
- Permitir que ONGs encontrem e reservem doações
- Tornar o processo:
  - Transparente
  - Organizado
  - Rastreável
- Centralizar todas as operações em uma única plataforma

---

## 🛠️ FUNCIONALIDADES

### 👤 USUÁRIOS
- Cadastro de Doadores e ONGs
- Login com autenticação
- Listagem de usuários cadastrados

### 📦 ITENS
- Cadastro de itens com:
  - Nome
  - Descrição
  - Categoria
  - Cidade
- Status:
  - Disponível
  - Reservado
  - Entregue

### 🔄 OPERAÇÕES
- Reserva de itens por ONGs
- Confirmação de entrega
- Cancelamento de reservas
- Persistência no SQLite

---

## 🧩 CONCEITOS UTILIZADOS

### 🧱 PROGRAMAÇÃO ORIENTADA A OBJETOS
- Classes: `Usuario`, `Doador`, `Ong`, `Item`, `Sistema`
- Encapsulamento
- Herança
- Polimorfismo
- Uso de ponteiros (`vector<Usuario*>`, `vector<Item*>`)

### 🗃️ CRUD
- Create
- Read
- Update
- Delete

---

## 📁 ESTRUTURA DO PROJETO

```bash
📂 doacoes-ongs/
├── src/
├── doacoes_demo.db
├── DoeFácil2.exe
└── README.md
```

---
## 🧭 Fluxo Básico de Operações

Usuário acessa o menu principal via terminal. Escolhe entre cadastrar, fazer login ou acessar funcionalidades específicas. Doadores podem doar itens; ONGs podem buscar e reservar itens. Todas as ações atualizam o banco de dados SQLite automaticamente. Dados são preservados para sessões futuras.

---
## ✅ PRÉ-REQUISITOS

Para executar o projeto, é necessário ter:


- Compilador C++ (g++ ou MinGW)
- Sistema operacional Windows ou compatível
- SQLite (já incluso no projeto)
- Terminal ou IDE (VS Code, CLion, etc.)

---

## 🚀 COMO RODAR O PROJETO

### 📥 CLONAR O REPOSITÓRIO
```bash
git clone https://github.com/guilhermebs7/doacoes-ongs.git
```
### 📂 NAVEGUE ATÉ A PASTA DO PROJETO 
```bash
cd doacoes-ongs
```
### ⚙️ COMPILE O PROJETO
```bash
gcc -c sqlite3.c -o sqlite3.o g++ main.cpp sistema.cpp Doador.cpp Ong.cpp Usuario.cpp Item.cpp sqlite3.o -o sistema.exe
  Execute o sistema:
./doacoes
   Ou, caso esteja no Windows:
DoeFácil2.exe
```
---

## 🎓 CRÉDITOS
Guilherme Barbosa  
Flávia Vitória  
Thiago Bernardo  
Rodrigo Neves  



