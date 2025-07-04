#include "sistema.h"
#include "Doador.h"
#include "Ong.h"
#include "Item.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include <limits>

using namespace std;

// ponteiro estático
Sistema* Sistema::instancia = nullptr;

Sistema::Sistema() {                    // construtor da classe Sistema
    cout << "Sistema iniciado.\n";
    conectarBanco();                   // Abre conexão com o banco de dados SQLite
}

Sistema* Sistema::getInstancia() {    // método estático que implementa o padrão Singleton
    if (instancia == nullptr)
        instancia = new Sistema();    // cria a instância se ainda não existir
    return instancia;
}

void Sistema::conectarBanco() {                                   // método que conecta ao banco SQLite
    int rc = sqlite3_open("doacoes_demo.db", &db);                // Abre banco
    if (rc) {
        cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << endl;
        db = nullptr;
    } else {
        cout << "Conectado ao banco SQLite com sucesso.\n";
    }
}

void Sistema::desconectarBanco() {                // método que fecha a conexão com o banco
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}


void Sistema::cadastrarUsuario(int tipo) {      // método para cadastrar usuário (Doador ou ONG)
    string nome, email, senha;
    cout << "Nome: "; getline(cin, nome);
    cout << "Email: "; getline(cin, email);
    cout << "Senha: "; getline(cin, senha);

    char* errMsg = nullptr;
    string sql;


    
    if (tipo == 1) {                               // cadastro de doador
        string cpf;
        cout << "CPF: "; getline(cin, cpf);
        usuarios.push_back(new Doador(nome, email, senha));
        sql = "INSERT INTO doadores (nome, email, senha, cpf) VALUES ('" + nome + "', '" + email + "', '" + senha + "', '" + cpf + "');";         // monta SQL para inserir no banco
  
    } else if (tipo == 2) {                    // cadastro de ONG
        string nomeOng, cnpj;
        cout << "Nome da ONG: "; getline(cin, nomeOng);
        cout << "CNPJ (14 digitos): "; getline(cin, cnpj);
        if (Ong::validarCnpj(cnpj)) {
            usuarios.push_back(new Ong(nome, email, senha, nomeOng, cnpj));
            sql = "INSERT INTO ongs (nome, email, senha, cnpj, nome_ong) VALUES ('" + nome + "', '" + email + "', '" + senha + "', '" + cnpj + "', '" + nomeOng + "');";
        } else {
            cout << "CNPJ invalido.\n";
            return;
        }
    } else {
        cout << "Opção invalida.\n";
        return;
    }

    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {  // executa o SQL para salvar no banco
        cerr << "Erro ao inserir usuario: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Usuario salvo no banco com sucesso!\n";
    }
}


bool Sistema::login() {                        // método de login de usuário (Doador ou ONG)
    string email, senha;
    cout << "Email: "; cin >> email;
    cout << "Senha: "; cin >> senha;

       // tenta login como doador
    string sql = "SELECT nome FROM doadores WHERE email='" + email + "' AND senha='" + senha + "';";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK && sqlite3_step(stmt) == SQLITE_ROW) {
        cout << "Login realizado como doador: " << sqlite3_column_text(stmt, 0) << "\n";
        sqlite3_finalize(stmt);
        return true;
    }
       // tenta login como ONG
    sql = "SELECT nome FROM ongs WHERE email='" + email + "' AND senha='" + senha + "';";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK && sqlite3_step(stmt) == SQLITE_ROW) {
        cout << "Login realizado como ONG: " << sqlite3_column_text(stmt, 0) << "\n";
        sqlite3_finalize(stmt);
        return true;
    }
    
    // caso não encontre
    cout << "Email ou senha invalidos.\n";
    sqlite3_finalize(stmt);
    return false;
}

void Sistema::doarItem() {                        // método para doar um item (apenas doador)
    string email;
    cout << "Email do doador: ";
    cin >> email;

    for (auto* u : usuarios) {                      // procura doador na lista de usuarios
        Doador* d = dynamic_cast<Doador*>(u);
        if (d && d->getEmail() == email) {
            cin.ignore();
            long id;
            string nomeItem, descricao, cidade;
            int categoriaInt;

            cout << "ID do item: "; cin >> id;
            cin.ignore();
            cout << "Nome do item: "; getline(cin, nomeItem);
            cout << "Descricao: "; getline(cin, descricao);
            cout << "Cidade: "; getline(cin, cidade);
            cout << "Categoria (0:Alimento, 1:Roupa, 2:Moveis, 3:Eletrodomesticos, 4:Higiene, 5:Didaticos): ";
            cin >> categoriaInt;

            string categorias[] = {"ALIMENTO", "ROUPA", "MOVEIS", "ELETRODOMESTICOS", "HIGIENE_PESSOAL", "MATERIAIS_DIDATICOS"};        // mapeia número da categoria para string
            string categoriaStr = categorias[categoriaInt];

            d->doarItem(id, nomeItem, descricao, categoriaStr, cidade);                                             // adiciona item no vetor do doador e no vetor geral de itens
            itens.push_back(d->getDoadorItens().back());

            // insere no banco
            string sql = "INSERT INTO itens (nome, descricao, categoria, cidade, dono_email, status) VALUES ('" +
                         nomeItem + "', '" + descricao + "', '" + categoriaStr + "', '" + cidade + "', '" + email + "', 'DISPONIVEL');";

            char* errMsg = nullptr;
            if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
                cerr << "Erro ao salvar item: " << errMsg << endl;
                sqlite3_free(errMsg);
            } else {
                cout << "Item doado e salvo no banco.\n";
            }
            return;
        }
    }

    cout << "Doador nao encontrado.\n";
}



void Sistema::solicitarItem() {          // método para ONG solicitar um item
    long id;
    string email;
    cout << "Email da ONG: "; cin >> email;
    cout << "ID do item desejado: "; cin >> id;

    string sql = "UPDATE itens SET status='RESERVADO' WHERE id=" + to_string(id) + " AND status='DISPONIVEL';";                      // atualiza status do item para RESERVADO
    char* errMsg = nullptr;

    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK) {
        cout << "Item reservado com sucesso.\n";
    } else {
        cerr << "Erro ao reservar item: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Sistema::confirmarEntrega() {                     // método para confirmar entrega do item
    long id;
    cout << "ID do item a ser entregue: ";
    cin >> id;

    string sql = "UPDATE itens SET status='ENTREGUE' WHERE id=" + to_string(id) + " AND status='RESERVADO';";                         // atualiza status do item para ENTREGUE
    char* errMsg = nullptr;

    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK) {
        cout << "Entrega confirmada.\n";
    } else {
        cerr << "Erro ao confirmar entrega: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

//NOVOS MÉTODOS AUXILIARES DO MENU 
void Sistema::listarUsuariosSalvos() {                                 // método para listar todos os usuários salvos no banco
    cout << "\n--- DOADORES ---\n";
    sqlite3_stmt* stmt;
    string sql = "SELECT nome, email, cpf FROM doadores;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << "Nome: " << sqlite3_column_text(stmt, 0)
                 << " | Email: " << sqlite3_column_text(stmt, 1)
                 << " | CPF: " << sqlite3_column_text(stmt, 2) << "\n";
        }
    }
    sqlite3_finalize(stmt);

    cout << "\n--- ONGs ---\n";
    sql = "SELECT nome, email, cnpj, nome_ong FROM ongs;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << "Nome Resp: " << sqlite3_column_text(stmt, 0)
                 << " | Email: " << sqlite3_column_text(stmt, 1)
                 << " | CNPJ: " << sqlite3_column_text(stmt, 2)
                 << " | ONG: " << sqlite3_column_text(stmt, 3) << "\n";
        }
    }
    sqlite3_finalize(stmt);
}

void Sistema::listarItensSalvos() {                                                // método para listar todos os itens cadastrados
    cout << "\n--- ITENS CADASTRADOS ---\n";
    string sql = "SELECT id, nome, descricao, categoria, cidade, status FROM itens;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << "ID: " << sqlite3_column_int(stmt, 0)
                 << " | Nome: " << sqlite3_column_text(stmt, 1)
                 << " | Desc: " << sqlite3_column_text(stmt, 2)
                 << " | Categoria: " << sqlite3_column_text(stmt, 3)
                 << " | Cidade: " << sqlite3_column_text(stmt, 4)
                 << " | Status: " << sqlite3_column_text(stmt, 5) << "\n";
        }
    }
    sqlite3_finalize(stmt);            // finaliza o statement SQLite:
}
