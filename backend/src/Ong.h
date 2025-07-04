// Ong.h
#ifndef ONG_H
#define ONG_H

#include "Usuario.h"
#include "Item.h" // Para usar ponteiros de Item
#include <string>
#include <vector>

using namespace std;

class Ong : public Usuario {
private:
    string cnpj;
    string nomeDaOng;
    vector<Item*> historicoItensRecebidos;

public:
    // Construtor
    Ong(const string& nome, const string& email, const string& senha,
        const string& nomeDaOng, const string& cnpj);

    // Getters
    string getCnpj() const;
    string getNomeDaOng() const;

    // Métodos principais
    void buscarItem(const vector<Item*>& itensDisponiveis); 
    void solicitarItem(Item* item); 
    void listarRecebidos() const; 
    
    void exibirPerfil() const override;

    // Validação
    static bool validarCnpj(const string& cnpj);
};

#endif
