#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Usuario.h"   // Base abstrata para Doador e ONG a ser definida por rodrigo
#include "Item.h"
#include "Doador.h"
#include "Ong.h"
#include <sqlite3.h> // Biblioteca SQLite para persistência de dados



class Sistema {
private:
    
    static Sistema* instancia;
    Sistema(); 

    std::vector<Usuario*> usuarios;       // polimórfico de usuários
    std::vector<Item*> itens;             // ponteiros para itens
    sqlite3* db;
   


public:
   
    static Sistema* getInstancia();

    void conectarBanco();     // Conecta ao banco PostgreSQL
    void desconectarBanco();  // Encerra a conexão


    // CRUD
    void cadastrarUsuario();     // Cadastra doador ou ONG
    bool login();                // Autenticação de usuário
    void buscarItens();          // Busca com filtros
    void doarItem();             // Interação: doador adiciona item
    void solicitarItem();        // ONG solicita item
    void confirmarEntrega();     // Confirmação de entrega

    // Persistência (bônus)
    void salvarDados();          // Salva dados em arquivo
    void carregarDados();        // Carrega dados de arquivo
};

#endif