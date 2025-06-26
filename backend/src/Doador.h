#ifndef DOADOR_H
#define DOADOR_H

#include "Usuario.h"
#include "Item.h"
#include <vector>
#include <string>

using namespace std;

class Doador : public Usuario {
private:
    vector<Item*> itensDoado;

public:
    Doador(const string& nome, const string& email, const string& senha);

    void doarItem(long id, const string& nomeItem, const string& descricao,
                  const string& categoria, const string& cidade);

    void listarItensDoado() const;
    const vector<Item*>& getDoadorItens() const { return itensDoado; }

    void exibirPerfil() const override;
};

#endif
