#include "Item.h"  // inclui a definição da classe Item e suas dependências
#include <iostream>
using namespace std;

Item::Item(long id, const string& nome, const string& descricao,         // construtor da classe Item,inicializa o item com os parâmetros fornecidos
           Categoria categoria, Doador* dono, const string& cidade)
    : id(id), categoria(categoria), status(Status::DISPONIVEL), dono(dono) {

    if (nome.empty()) {                // validação: nome não pode ser vazio
        throw invalid_argument("O nome do item não pode estar em branco.");
    }
    if (descricao.empty()) {
        throw invalid_argument("A descrição do item não pode estar em branco.");
    }
    if (cidade.empty()) {
        throw invalid_argument("A cidade do item não pode estar em branco.");
    }

    this->nome = nome;
    this->descricao = descricao;
    this->cidade = cidade;
}

long Item::getId() const { return id; }   //retorna id do item

string Item::getNome() const { return nome; }  // nome do item

Doador* Item::getDono() const { return dono; }  // retorna um ponteiro para o doador do item

void Item::alterarStatus(Status novoStatus) {    // altera o status atual do item para o novo status fornecido
    status = novoStatus;
}

void Item::cancelarReserva() {              // Cancela uma reserva caso o item esteja reservado 
    if (status == Status::RESERVADO) {
        status = Status::DISPONIVEL;
        cout << "Reserva cancelada com sucesso para o item: " << nome << endl;
    } else {
        cout << "O item não está reservado. Cancelamento não realizado." << endl;
    }
}

void Item::exibirItem() const {               //exibe as informações do item no console
    cout << "ID: " << id
         << "\nNome: " << nome
         << "\nDescrição: " << descricao
         << "\nCategoria: " << categoriaParaString(categoria)
         << "\nStatus: " << statusParaString(status)
         << "\nCidade: " << cidade << "\n";
}

string Item::statusParaString(Status s) const {      // converte o status enum em uma string para exibição
    switch (s) {
        case Status::DISPONIVEL: return "Disponível";
        case Status::RESERVADO: return "Reservado";
        case Status::ENTREGUE: return "Entregue";
        default: return "Desconhecido";
    }
}

string Item::categoriaParaString(Categoria c) const {    // converte a categoria enum em uma string para exibição
    switch (c) {
        case Categoria::ALIMENTO: return "Alimento";
        case Categoria::ROUPA: return "Roupa";
        case Categoria::MOVEIS: return "Móveis";
        case Categoria::ELETRODOMESTICOS: return "Eletrodomésticos";
        case Categoria::HIGIENE_PESSOAL: return "Higiene Pessoal";
        case Categoria::MATERIAIS_DIDATICOS: return "Materiais Didáticos";
        default: return "Desconhecida";
    }
}
