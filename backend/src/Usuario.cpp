#include "Usuario.h"

// Construtor
Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& senha)
    : nome(nome), email(email), senha(senha) {}

// Getters e Setters
std::string Usuario::getNome() const {
    return nome;
}

void Usuario::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Usuario::getEmail() const {
    return email;
}

void Usuario::setEmail(const std::string& email) {
    this->email = email;
}

std::string Usuario::getSenha() const {
    return senha;
}

void Usuario::setSenha(const std::string& senha) {
    this->senha = senha;
}
