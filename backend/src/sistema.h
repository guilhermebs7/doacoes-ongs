#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <vector>
#include <string>
//#include "Usuario.hpp"   // Base abstrata para Doador e ONG a ser definida por rodrigo
//#include "Item.hpp"      // Classe dos itens a ser definida

class Sistema {
private:
    
    static Sistema* instancia;
    Sistema(); // Construtor privado

    //std::vector<Usuario*> usuarios;       // Vetor polimórfico de usuários
    //std::vector<Item*> itens;             // Vetor de ponteiros para itens

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