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
    cout << "Itens disponíveis para solicitação:\n";
    bool encontrou = false;

    for (const auto& item : itensDisponiveis) {
        if (item->getStatus() == Status::DISPONIVEL) {
            item->exibirItem();
            cout << "------------------" << endl;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhum item disponível no momento.\n";
    }
}

// Método para solicitar/reservar um item
void Ong::solicitarItem(Item* item) {
    if (item->getStatus() == Status::DISPONIVEL) {
        item->alterarStatus(Status::RESERVADO);
        historicoItensRecebidos.push_back(item);
        cout << "Item '" << item->getNome() << "' reservado com sucesso pela ONG '" << nomeDaOng << "'.\n";
    } else {
        cout << "O item '" << item->getNome() << "' não está disponível para reserva.\n";
    }
}

// Método herdado de Usuario - exibe os dados da ONG
void Ong::exibirPerfil() const {
    cout << "===== PERFIL DA ONG =====" << endl;
    cout << "Nome do Responsável: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Nome da ONG: " << nomeDaOng << endl;
    cout << "CNPJ: " << cnpj << endl;
}