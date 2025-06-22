#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

enum class Status { DISPONIVEL, RESERVADO, ENTREGUE };

class Doador; 

class Item {
private:
    long id;
    string nome;
    string descricao;
    string categoria;
    Status status;
    Doador* dono;
    string cidade;

public:
    Item(long id, const string& nome, const string& descricao,
         const string& categoria, Doador* dono, const string& cidade);

    long getId() const; 
    string getNome() const;
    string getCategoria() const { return categoria; }
    string getCidade() const { return cidade; }
    Status getStatus() const { return status; }
    Doador* getDono() const;

    void alterarStatus(Status novoStatus);
    void cancelarReserva();
    void exibirItem() const;
    string statusParaString(Status s) const;
};

#endif
