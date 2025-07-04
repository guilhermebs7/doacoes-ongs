#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string senha;

public:
    Usuario(const std::string& nome, const std::string& email, const std::string& senha);
    virtual ~Usuario() {}

    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string getSenha() const;
    void setSenha(const std::string& senha);

    virtual void exibirPerfil() const = 0; // Método virtual puro (abstrato)
};

#endif