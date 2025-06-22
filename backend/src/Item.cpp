#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(long id, const string& nome, const string& descricao,
           const string& categoria, Doador* dono, const string& cidade)
    : id(id), nome(nome), descricao(descricao), categoria(categoria),
      status(Status::DISPONIVEL), dono(dono), cidade(cidade) {}

long Item::getId() const { return id; }

string Item::getNome() const { return nome; }

Doador* Item::getDono() const { return dono; }

void Item::alterarStatus(Status novoStatus) {
    status = novoStatus;
}

void Item::cancelarReserva() {
    if (status == Status::RESERVADO) {
        status = Status::DISPONIVEL;
        cout << "Reserva cancelada com sucesso para o item: " << nome << endl;
    } else {
        cout << "O item não está reservado. Cancelamento não realizado." << endl;
    }
}

void Item::exibirItem() const {
    cout << "ID: " << id
         << "\nNome: " << nome
         << "\nDescrição: " << descricao
         << "\nCategoria: " << categoria
         << "\nStatus: " << statusParaString(status)
         << "\nCidade: " << cidade << "\n";
}

string Item::statusParaString(Status s) const {
    switch (s) {
        case Status::DISPONIVEL: return "Disponível";
        case Status::RESERVADO: return "Reservado";
        case Status::ENTREGUE: return "Entregue";
        default: return "Desconhecido";
    }
}
