#include <iostream>
#include "Doador.h"
#include "Ong.h"
#include "Item.h"
#include "sistema.h"

using namespace std;

int main() {
    // Criando instância única do sistema
    Sistema* sistema = Sistema::getInstancia();

    // Criando um doador
    Doador* doador1 = new Doador("João", "joao@email.com", "senha123");

    // Criando uma ONG
    Ong* ong1 = new Ong("Lar Esperança", "contato@laresperanca.org", "senha456", "Lar Esperança", "12345678000190");

    // Doador doa item
    doador1->doarItem(1, "Cesta Básica", "Alimentos não perecíveis", "ALIMENTO", "Recife");
    doador1->doarItem(2, "Blusas de Frio", "Roupas de inverno", "ROUPA", "Recife");

    // Listando os itens doados
    cout << "\n--- Itens doados por João ---" << endl;
    doador1->listarItensDoado();

    // ONG busca e solicita um item do doador
    const vector<Item*>& itensDisponiveis = doador1->getDoadorItens();
    cout << "\n--- ONG buscando itens disponíveis ---" << endl;
    ong1->buscarItem(itensDisponiveis);

    if (!itensDisponiveis.empty()) {
        cout << "\n--- ONG solicitando o primeiro item ---" << endl;
        ong1->solicitarItem(itensDisponiveis[0]);

        // Teste: mostrar status após reserva
        cout << "\nStatus após reserva do item:\n";
        itensDisponiveis[0]->exibirItem();
    }

    // Mostrar perfil dos usuários
    cout << "\n--- Perfil do Doador ---" << endl;
    doador1->exibirPerfil();

    cout << "\n--- Perfil da ONG ---" << endl;
    ong1->exibirPerfil();

    // Libera memória (se não estiver usando smart pointers)
    delete doador1;
    delete ong1;

    return 0;
}
