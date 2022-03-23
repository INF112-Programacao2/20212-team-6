#include <string>
#include <iostream>

#include "Administrador.h"

Estoque Administrador::EstoqueDaLoja = {};

Administrador::Administrador(std::string nome, int cpf, int id) : Usuario(nome,cpf,id) {}

void Administrador::adicionarProduto() {
    EstoqueDaLoja.adicionar_produto();
}

void Administrador::relatorioDeEstoque() {          // será melhorada quando for feito um estoque mais organizado
    EstoqueDaLoja.Relatorio();
}

void Administrador::menuAdm() {
    int opcao;
    while (opcao != 3) {            // haverão mais opcoes conforme a necessidade de mais operações
        inicioMenu:
        std::cout << std::endl;
        std::cout << "________________________ MENU DO ADMINISTRADOR _______________________\n";
        std::cout << std::endl;
        std::cout << "\t1) Adicionar produto ao estoque\n";
        std::cout << std::endl;
        std::cout << "\t2) Consultar estoque\n";
        std::cout << std::endl;
        std::cout << "\t3) Finalizar sessão\n";
        std::cout << std::endl;
        std::cout << "______________________________________________________________________\n";
        std::cout << std::endl;
        std::cout << "\tSelecione uma opção: ";
        std::cin >> opcao;
        std::cout << std::endl;

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
                std::cout << "Opção invalida! Selecione uma das opções DO MENU\n";
                goto inicioMenu;            // vai para o início do menu
                break;
        }
    }
}
