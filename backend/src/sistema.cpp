#include "sistema.h"
#include "Doador.h"
#include "Ong.h"
#include "Item.h"
#include <iostream>    
#include <typeinfo>    // p identificação de tipo em tempo de execução 
#include <limits>      // p limites de tipos numéricos 

using namespace std;

// ponteiro estático da classe Sistema como nullptr
Sistema* Sistema::instancia = nullptr;

// exibe uma msg no console quando o sistema é instanciado
Sistema::Sistema() {
    std::cout << "Sistema iniciado.\n";
}

// método estático que retorna a instância única do sistema Singleton
Sistema* Sistema::getInstancia() {
    if (instancia == nullptr)         // se existe alguma instância
        instancia = new Sistema();    // se não, cria uma nova
        return instancia;
    }


void Sistema::cadastrarUsuario(){
    int tipo;
    cout << "Cadastrar: 1 - Doador | 2 - ONG: ";
    cin >> tipo;
    cin.ignore();

    string nome, email, senha;
    cout << "Nome: "; getline(cin, nome);
    cout << "Email: "; getline(cin, email);
    cout << "Senha: "; getline(cin, senha);

    if (tipo == 1) {
        string cpf;
        cout << "CPF: "; getline(cin, cpf);
        usuarios.push_back(new Doador(nome, email, senha));
        cout << "Doador cadastrado com sucesso.\n";
    }else if (tipo == 2){
        string nomeOng, cnpj;
        cout << "Nome da ONG: "; getline(cin, nomeOng);
        cout << "CNPJ (14 dígitos): "; getline(cin, cnpj);

        if (Ong::validarCnpj(cnpj)) {
            usuarios.push_back(new Ong(nome, email, senha, nomeOng, cnpj));
            cout << "ONG cadastrada com sucesso.\n";
        } else {
            cout << "CNPJ inválido.\n";
        }
    }else{
        cout << "Opção inválida.\n";
    }
}

bool Sistema::login() {
    string email, senha;
    cout << "Email: "; cin >> email;
    cout << "Senha: "; cin >> senha;

    for (auto* u : usuarios) {
        if (u->getEmail() == email && u->getSenha() == senha) {
            cout << "Login realizado com sucesso como: " << typeid(*u).name() << "\n";
            u->exibirPerfil();
            return true;
        }
    }
    cout << "Email ou senha inválidos.\n";
    return false;
}

void Sistema::doarItem() {
    string email;
    cout << "Email do doador: ";
    cin >> email;

    for (auto* u : usuarios) {
        Doador* d = dynamic_cast<Doador*>(u);
        if (d && d->getEmail() == email) {
            cin.ignore();
            long id;
            string nomeItem, descricao, cidade;
            int categoriaInt;

            cout << "ID do item: "; cin >> id;
            cin.ignore();
            cout << "Nome do item: "; getline(cin, nomeItem);
            cout << "Descrição: "; getline(cin, descricao);
            cout << "Cidade: "; getline(cin, cidade);

            cout << "Categoria (0:Alimento, 1:Roupa, 2:Móveis, 3:Eletrodomésticos, 4:Higiene, 5:Didáticos): ";
            cin >> categoriaInt;

            Categoria categoria = static_cast<Categoria>(categoriaInt);

            // Convert Categoria enum to string
            std::string categoriaStr;
            switch (categoria) {
                case Categoria::ALIMENTO: categoriaStr = "Alimento"; break;
                case Categoria::ROUPA: categoriaStr = "Roupa"; break;
                case Categoria::MOVEIS: categoriaStr = "Móveis"; break;
                case Categoria::ELETRODOMESTICOS: categoriaStr = "Eletrodomésticos"; break;
                case Categoria::HIGIENE_PESSOAL: categoriaStr = "Higiene"; break;
                case Categoria::MATERIAIS_DIDATICOS: categoriaStr = "Didáticos"; break;
                default: categoriaStr = "Desconhecido"; break;
            }

            d->doarItem(id, nomeItem, descricao, categoriaStr, cidade);
            itens.push_back(d->getDoadorItens().back());
            return;
        }
    }

    cout << "Doador não encontrado.\n";
}

void Sistema::buscarItens() {
    int categoriaInt;
    string cidade;
    cout << "Filtrar por cidade: "; cin.ignore(); getline(cin, cidade);
    cout << "Filtrar por categoria (0-5): "; cin >> categoriaInt;
    Categoria catFiltro = static_cast<Categoria>(categoriaInt);

    for (const auto& item : itens) {
        if (item->getStatus() == Status::DISPONIVEL &&
            item->getCategoria() == catFiltro &&
            item->getCidade() == cidade) {
            item->exibirItem();
            cout << "--------------------\n";
        }
    }
}

void Sistema::solicitarItem() {
    long id;
    string email;
    cout << "Email da ONG: "; cin >> email;
    cout << "ID do item desejado: "; cin >> id;

    for (auto* u : usuarios) {
        Ong* o = dynamic_cast<Ong*>(u);
        if (o && o->getEmail() == email) {
            for (auto* item : itens) {
                if (item->getId() == id) {
                    o->solicitarItem(item);
                    return;
                }
            }
        }
    }

    cout << "ONG ou item não encontrado.\n";
}

void Sistema::confirmarEntrega() {
    long id;
    cout << "ID do item a ser entregue: ";
    cin >> id;

    for (auto* item : itens) {
        if (item->getId() == id && item->getStatus() == Status::RESERVADO) {
            item->alterarStatus(Status::ENTREGUE);
            cout << "Entrega confirmada para o item: " << item->getNome() << endl;
            return;
        }
    }
    cout << "Item não encontrado ou não reservado.\n";
}

void Sistema::salvarDados() {
    cout << "[BONUS] Salvando dados... (não implementado)\n";
    // Aqui entraria lógica para salvar usuários e itens em arquivos ou banco
}

void Sistema::carregarDados() {
    cout << "[BONUS] Carregando dados... (não implementado)\n";
    // Aqui entraria lógica para carregar dados de arquivos ou banco
}
