#include <string>
#include <iostream>
#include <exception>

#include "Administrador.h"

Estoque Administrador::EstoqueDaLoja = {};

Administrador::Administrador(std::string nome, int cpf, int id) : Usuario(nome, cpf, id) {}

void Administrador::adicionarProduto() {
    EstoqueDaLoja.adicionar_produto();
}

void Administrador::relatorioDeEstoque() {          // sera melhorada quando for feito um estoque mais organizado
    EstoqueDaLoja.Relatorio();
}

void Administrador::menuAdm() {
    int opcao=-1;
    std::string op = "";
    while (opcao != 3) {           
    inicioMenu:
        std::cout << std::endl;
        std::cout << "________________________ MENU DO ADMINISTRADOR _______________________\n";
        std::cout << std::endl;
        std::cout << "\t1) Adicionar produto ao estoque\n";
        std::cout << std::endl;
        std::cout << "\t2) Consultar estoque\n";
        std::cout << std::endl;
        std::cout << "\t3) Finalizar sessao\n";
        std::cout << std::endl;
        std::cout << "______________________________________________________________________\n";
        std::cout << std::endl;
        std::cout << "\tSelecione uma opcao: ";
        std::cin >> op;
        std::cout << std::endl;

        system("clear"); // limpa a tela do terminal

        //  acoes a serem executadas de acordo com a escolha do usuario
        try {
            opcao = std::stoi(op);
        }
        catch (std::invalid_argument e)
        {
            
        }



        switch (opcao) {
        case 1:
            adicionarProduto();
            std::cout << std::endl;
            break;
        case 2:
            relatorioDeEstoque();
            break;
        case 3:
            std::cout << "FIM DA SESSAO!\n";
            break;
        default:
            std::cout << "Opcao invalida! Selecione uma das opcoes DO MENU\n";
            goto inicioMenu;            // vai para o inicio do menu
            break;
        }
    }
}
