// Ong.cpp
#include "Ong.h"
#include <iostream>
#include <regex>

using namespace std;

// Construtor
Ong::Ong(const string& nome, const string& email, const string& senha,
         const string& nomeDaOng, const string& cnpj)
    : Usuario(nome, email, senha), nomeDaOng(nomeDaOng), cnpj(cnpj) {}

// Getters
string Ong::getCnpj() const {
    return cnpj;
}

string Ong::getNomeDaOng() const {
    return nomeDaOng;
}

// Método para listar todos os itens recebidos pela ONG
void Ong::listarRecebidos() const {
    cout << "Itens recebidos pela ONG '" << nomeDaOng << "':" << endl;

    if (historicoItensRecebidos.empty()) {
        cout << "Nenhum item recebido ainda." << endl;
        return;
    }

    for (const auto& item : historicoItensRecebidos) {
        item->exibirItem();
        cout << "------------------" << endl;
    }
}

// Validação simples de CNPJ (apenas formato: 14 dígitos)
bool Ong::validarCnpj(const string& cnpj) {
    regex cnpjRegex("\\d{14}"); // Exemplo: 12345678000199
    return regex_match(cnpj, cnpjRegex);
}

// Método para buscar itens disponíveis (filtrar por categoria/cidade etc)
void Ong::buscarItem(const vector<Item*>& itensDisponiveis) {
    // Lógica será implementada em conjunto com a classe Item
    cout << "[buscarItem ainda não implementado]" << endl;
}

// Método para solicitar/reservar um item
void Ong::solicitarItem(Item* item) {
    // Lógica será implementada com base em como os status dos itens forem definidos
    cout << "[solicitarItem ainda não implementado]" << endl;
}
