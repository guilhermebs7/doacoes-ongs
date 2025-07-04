#include <iostream>                  // Entrada e saída padrão
#include <limits>                   // Para usar limites numéricos, útil ao limpar buffer
#include <string>                   // Para manipular strings
#include "Doador.h"                 // Inclusão da classe Doador
#include "Ong.h"                    // Inclusão da classe Ong
#include "Item.h"                   // Inclusão da classe Item
#include "sistema.h"                // Inclusão da classe principal do sistema

#ifdef _WIN32                       // Verifica se o sistema é Windows
#include <cstdlib>
#define CLEAR_SCREEN "cls"          // Comando para limpar tela no Windows
#else
#define CLEAR_SCREEN "clear"        // Comando para limpar tela no Linux/Mac
#endif

using namespace std;

// Função que limpa a tela do terminal
void limparTela() {
    system(CLEAR_SCREEN);          // Executa o comando apropriado
}

// Função que pausa o programa até o usuário apertar Enter
void pausar() {
    cin.clear();                                       // Limpa possíveis flags de erro
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora qualquer entrada anterior
    cout << "\nPressione Enter para continuar...";
    cin.get();                                         // Aguarda o Enter
}

// Função genérica para ler um número inteiro com validação
bool validarEntradaNumerica(int& valor, const string& mensagem) {
    cout << mensagem;
    while (!(cin >> valor)) {
        cout << "Entrada inválida! Por favor, digite um número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer após número
    return true;
}

// Exibe o menu principal do sistema com todas as opções
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
    cout << "4. Solicitar item          (Reserve um item para sua ONG)\n";
    cout << "5. Confirmar entrega        (Confirme a entrega de um item reservado)\n";
    cout << "6. Listar usuarios         (Veja todos os usuarios cadastrados)\n";
    cout << "7. Listar itens            (Veja todos os itens no sistema)\n";
    cout << "0. Sair                    (Encerre o programa)\n";
    cout << "Escolha uma opcao: ";
}

// Submenu que pergunta se o usuário deseja cadastrar como Doador ou ONG
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

// Função principal que executa o loop do programa
int main() {
    Sistema* sis = Sistema::getInstancia();   // Obtém instância única do sistema (singleton)
    int opc = -1;                             // Armazena a opção do usuário

    // Loop principal do menu
    while (true) {
        exibirMenuPrincipal();                // Exibe o menu
        if (!validarEntradaNumerica(opc, "")) continue;

        switch (opc) {
            case 1: {
                // Cadastro de usuário
                int tipoUsuario;
                exibirSubmenuCadastro();                  // Pergunta se é doador ou ONG
                if (!validarEntradaNumerica(tipoUsuario, "")) continue;

                if (tipoUsuario == 1 || tipoUsuario == 2) {
                    sis->cadastrarUsuario(tipoUsuario);  // Cadastra de acordo com o tipo
                } else if (tipoUsuario == 0) {
                    continue;                            // Volta ao menu principal
                } else {
                    cout << "Opção invalida. Tente novamente.\n";
                }
                pausar();
                break;
            }
            case 2: {
                // Login
                if (sis->login()) {
                    cout << "Login bem-sucedido!\n";
                } else {
                    cout << "Falha no login. Verifique email e senha.\n";
                }
                pausar();
                break;
            }
            case 3: {
                // Doação de item
                sis->doarItem();
                pausar();
                break;
            }
            case 4: {
                // Solicitação de item pela ONG
                sis->solicitarItem();
                pausar();
                break;
            }
            case 5: {
                // Confirmação de entrega
                sis->confirmarEntrega();
                pausar();
                break;
            }
            case 6: {
                // Lista todos os usuários (doadores e ONGs)
                sis->listarUsuariosSalvos();
                pausar();
                break;
            }
            case 7: {
                // Lista todos os itens (doações registradas)
                sis->listarItensSalvos();
                pausar();
                break;
            }
            case 0: {
                // Encerra o sistema
                limparTela();
                cout << "Obrigado por usar o Doe Facil! Ate logo!\n";
                return 0;
            }
            default: {
                // Tratamento de erro para opção inválida
                cout << "Opção invalida. Por favor, escolha uma opção valida.\n";
                pausar();
            }
        }
    }

    return 0;
}
