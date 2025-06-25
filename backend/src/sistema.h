#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <vector>
#include <string>
#include "Usuario.h"   // Base abstrata para Doador e ONG a ser definida por rodrigo
#include "Item.h"
#include "Doador.h"
#include "Ong.h"


class Sistema {
private:
    
    static Sistema* instancia;
    Sistema(); 

    std::vector<Usuario*> usuarios;       // polimórfico de usuários
    std::vector<Item*> itens;             // ponteiros para itens

public:
   
    static Sistema* getInstancia();

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