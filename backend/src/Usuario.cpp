#include "Usuario.h"

// Construtor
Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& senha)
    : nome(nome), email(email), senha(senha) {}

// Getters e Setters
std::string Usuario::getNome() const {
    return nome;
}
// Atualiza o nome do usuário
void Usuario::setNome(const std::string& nome) {
    this->nome = nome;
}
// Retorna o email do usuário
std::string Usuario::getEmail() const {
    return email;
}
// Atualiza o email do usuário
void Usuario::setEmail(const std::string& email) {
    this->email = email;
}
// Retorna a senha do usuário
std::string Usuario::getSenha() const {
    return senha;
}
// Atualiza a senha do usuário
void Usuario::setSenha(const std::string& senha) {
    this->senha = senha;
}
