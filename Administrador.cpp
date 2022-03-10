#include <string>
#include <iostream>

#include "usuario.h"
#include "Administrador.h"
#include "Produto.h"
#include "Pedido.h"

Administrador::Administrador(std::string nome, int cpf) : Usuario(nome,cpf) {}

void Admin::adicionarProduto() {
    EstoqueDaLoja.adicionar_produto();
}

void Administrador::relatorioDeEstoque() {          // será melhorada quando for feito um estoque mais organizado
    EstoqueDaLoja.Relatorio();
}

void Administrador::menuAdm() {
    int opcao;
    while (opcao != 3) {            // haverão mais opcoes conforme a necessidade de mais operações
        inicioMenu:
        std::cout << "____________ MENU DO ADMINISTRADOR ___________\n";
        std::cout << "                                     \n";
        std::cout << "1) Adicionar produto ao estoque\n";
        std::cout << "2) Exibir produtos em estoque\n";
        std::cout << "3) Finalizar sessao\n";
        std::cout << "______________________________________________\n";
        std::cout << "Selecione uma opcao: ";
        std::cin >> opcao;

        system("clear"); // limpa a tela do terminal

        //  ações a serem executadas de acordo com a escolha do usuario

        switch (opcao) {
            case 1:
                adicionarProduto();
                std::cout << std::endl;
                break;
            case 2:
                relatorioDeEstoque();
                break;
            case 3:
                std::cout << "FIM DA SESSÃO!\n";
                break;
            default:
                std::cout << "Opcao invalida! Selecione uma das opcoes DO MENU\n";
                goto inicioMenu;            // vai para o início do menu
                break;
        }
    }
}
