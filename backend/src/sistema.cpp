#include "Sistema.h"
//#include "Doador.hpp"
//#include "Ong.hpp"
#include <iostream>    
#include <typeinfo>    // p identificação de tipo em tempo de execução 
#include <limits>      // p limites de tipos numéricos 

// Inicialização do ponteiro estático da classe Sistema como nullptr
Sistema* Sistema::instancia = nullptr;
//teste
// construtor
// exibe uma msg no console quando o sistema é instanciado
Sistema::Sistema() {
    std::cout << "Sistema iniciado.\n";
}

// método estático que retorna a instância única do sistema Singleton
Sistema* Sistema::getInstancia() {
    if (instancia == nullptr)         // se existe alguma instância
        instancia = new Sistema();    // se não, cria uma nova
    return instancia;