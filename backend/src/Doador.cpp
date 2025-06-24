#include "Doador.h"
#include <iostream>

using namespace std;

Doador::Doador(const string& nome, const string& email, const string& senha)
    : Usuario(nome, email, senha) {}

void Doador::doarItem(long id, const string& nomeItem, const string& descricao,
                      const string& categoria, const string& cidade) {
    Item* novo = new Item(id, nomeItem, descricao, categoria, this, cidade);
    itensDoado.push_back(novo);
    cout << "Item '" << nomeItem << "' doado com sucesso!\n";
}

void Doador::listarItensDoado() const {
    cout << "Itens doados por " << nome << ":\n";

    if (itensDoado.empty()) {
        cout << "Nenhum item doado ainda.\n";
        return;
    }

    for (const auto& item : itensDoado) {
        item->exibirItem();
        cout << "------------------" << endl;
    }
}

void Doador::exibirPerfil() const {
    cout << "===== PERFIL DO DOADOR =====\n";
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
}
