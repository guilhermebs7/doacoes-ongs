#include <iostream>
#include <limits>
#include <string>
#include "Doador.h"
#include "Ong.h"
#include "Item.h"
#include "sistema.h"

#ifdef _WIN32
#include <cstdlib>
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

// Função para limpar a tela
void limparTela() {
    system(CLEAR_SCREEN);
}

// Função para pausar a execução até o usuário pressionar Enter
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função para validar entrada numérica
bool validarEntradaNumerica(int& valor, const string& mensagem) {
    cout << mensagem;
    while (!(cin >> valor)) {
        cout << "Entrada inválida! Por favor, digite um número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

// Função para exibir o menu principal com título e descrição
void exibirMenuPrincipal() {
    limparTela();
    cout << "==============================================================\n";
    cout << "         Bem-vindo ao Doe Facil             \n";
    cout << "==============================================================\n";
    cout << "Um sistema para conectar doadores e ONGs, promovendo solidariedade!\n\n";
    cout << "=== MENU PRINCIPAL ===\n";
    cout << "1. Cadastrar usuario        (Crie uma conta como Doador ou ONG)\n";
    cout << "2. Login                   (Acesse sua conta para gerenciar doacoes)\n";
    cout << "3. Doar item               (Doe itens como alimentos, roupas, etc.)\n";
    cout << "4. Buscar itens disponiveis (Encontre itens para sua ONG)\n";
    cout << "5. Solicitar item          (Reserve um item para sua ONG)\n";
    cout << "6. Confirmar entrega        (Confirme a entrega de um item reservado)\n";
    cout << "7. Listar usuarios         (Veja todos os usuarios cadastrados)\n";
    cout << "8. Listar itens            (Veja todos os itens no sistema)\n";
    cout << "0. Sair                    (Encerre o programa)\n";
    cout << "Escolha uma opção: ";
}

// Função para exibir submenu de cadastro
void exibirSubmenuCadastro() {
    limparTela();
    cout << "==============================================================\n";
    cout << "              Cadastro de Novo Usuario                        \n";
    cout << "==============================================================\n";
    cout << "Selecione o tipo de usuario:\n";
    cout << "1. Doador (Pessoa física que deseja doar itens)\n";
    cout << "2. ONG    (Organização que deseja receber doacoes)\n";
    cout << "0. Voltar ao menu principal\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Sistema* sis = Sistema::getInstancia();
    int opc = -1;

    while (true) {
        exibirMenuPrincipal();
        if (!validarEntradaNumerica(opc, "")) continue;

        switch (opc) {
            case 1: {
                // Submenu para cadastro
                int tipoUsuario;
                exibirSubmenuCadastro();
                if (!validarEntradaNumerica(tipoUsuario, "")) continue;

                if (tipoUsuario == 1 || tipoUsuario == 2) {
                    sis->cadastrarUsuario();
                    pausar();
                } else if (tipoUsuario == 0) {
                    continue; // Volta ao menu principal
                } else {
                    cout << "Opção invalida. Tente novamente.\n";
                    pausar();
                }
                break;
            }
            case 2: {
                if (sis->login()) {
                    cout << "Login bem-sucedido!\n";
                } else {
                    cout << "Falha no login. Verifique email e senha.\n";
                }
                pausar();
                break;
            }
            case 3: {
                sis->doarItem();
                pausar();
                break;
            }
            case 4: {
                sis->buscarItens();
                pausar();
                break;
            }
            case 5: {
                sis->solicitarItem();
                pausar();
                break;
            }
            case 6: {
                sis->confirmarEntrega();
                pausar();
                break;
            }
            case 7: {
                sis->listarUsuariosSalvos();
                pausar();
                break;
            }
            case 8: {
                sis->listarItensSalvos();
                pausar();
                break;
            }
            case 0: {
                limparTela();
                cout << "Obrigado por usar o Doe Facil! Ate logo!\n";
                return 0;
            }
            default: {
                cout << "Opção invalida. Por favor, escolha uma opção valida.\n";
                pausar();
            }
        }
    }

    return 0;
}