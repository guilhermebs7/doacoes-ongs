#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <stdexcept>
using namespace std;

enum class Status { DISPONIVEL, RESERVADO, ENTREGUE };     // enumeração que define os possíveis status de um item

enum class Categoria {                                     // define as categorias possíveis de um item
    ALIMENTO,
    ROUPA,
    MOVEIS,
    ELETRODOMESTICOS,
    HIGIENE_PESSOAL,
    MATERIAIS_DIDATICOS
};

class Doador;                      //declaração antecipada da classe Doador 

class Item {                     // declaração da classe item 
private:
    long id;
    string nome;
    string descricao;
    Categoria categoria;
    Status status;
    Doador* dono;
    string cidade;

public:                                           //  construtor da classe Item
    Item(long id, const string& nome, const string& descricao,
         Categoria categoria, Doador* dono, const string& cidade);

    long getId() const;                             //retorna o id 
    string getNome() const;
    Categoria getCategoria() const { return categoria; }
    string getCidade() const { return cidade; }
    Status getStatus() const { return status; }
    Doador* getDono() const;

    void alterarStatus(Status novoStatus);
    void cancelarReserva();
    void exibirItem() const;
    string statusParaString(Status s) const;
    string categoriaParaString(Categoria c) const;
};

#endif
