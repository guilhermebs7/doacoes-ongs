#include "sistema.h"
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