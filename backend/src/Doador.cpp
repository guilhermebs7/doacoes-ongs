#include "Doador.h"
#include <iostream>
#include <stdexcept> // para std::invalid_argument

using namespace std;

// Função para converter string em enum Categoria
Categoria stringParaCategoria(const std::string& str) {
    if (str == "ALIMENTO") return Categoria::ALIMENTO;
    else if (str == "ROUPA") return Categoria::ROUPA;
    else if (str == "MOVEIS") return Categoria::MOVEIS;
    else if (str == "ELETRODOMESTICOS") return Categoria::ELETRODOMESTICOS;
    else if (str == "HIGIENE_PESSOAL") return Categoria::HIGIENE_PESSOAL;
    else if (str == "MATERIAIS_DIDATICOS") return Categoria::MATERIAIS_DIDATICOS;
    else throw invalid_argument("Categoria inválida");
}

Doador::Doador(const string& nome, const string& email, const string& senha)
    : Usuario(nome, email, senha) {}

void Doador::doarItem(long id, const string& nomeItem, const string& descricao,
                      const string& categoriaStr, const string& cidade) {
    Categoria categoria = stringParaCategoria(categoriaStr);
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
