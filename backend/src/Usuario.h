#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;   // Nome do usuário
    std::string email;  // Email do usuário
    std::string senha;  // Senha do usuário

public:
    Usuario(const std::string& nome, const std::string& email, const std::string& senha);
    virtual ~Usuario() {}

    // Métodos getters e setters
    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string getSenha() const;
    void setSenha(const std::string& senha);

    virtual void exibirPerfil() const = 0; // Método virtual puro (abstrato)
};

#endif
