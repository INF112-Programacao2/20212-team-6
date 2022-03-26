#include <string>
#include <iostream>
#include <exception>
#include <stdio.h>

#include "Administrador.h"

Estoque Administrador::EstoqueDaLoja = {};

Administrador::Administrador(std::string nome, int cpf, int id) : Usuario(nome,cpf,id) {}

void Administrador::adicionarProduto() {
    EstoqueDaLoja.adicionar_produto();
}

void Administrador::relatorioDeEstoque() {          // será melhorada quando for feito um estoque mais organizado
    EstoqueDaLoja.Relatorio();
}

void Administrador::excluirProduto() {  
    int opcao_geral;
    int opcao_consulta;
    // serão repassados para o método que exclui produto
    int codigo;
    int quantidade;

    menu_excluiProduto:
    std::cout << "__________________________ OPÇÕES __________________________\n";
    std::cout << std::endl;
    std::cout << "  1. REMOVER SOMENTE ALGUMAS UNIDADES DO PRODUTO\n";
    std::cout << "  2. REMOVER O PRODUTO DO ESTOQUE\n";
    std::cout << std::endl;
    std::cout << "____________________________________________________________\n";
    std::cout << std::endl;
    std::cout << "Digite uma das opções acima: ";
    std::cin >> opcao_geral;
    std::cout << std::endl;

    switch(opcao_geral)
    {
        case 1:
        {   
            // o usuário informará um código, que será usado para buscar pelo produto no estoque, e uma quantidade
            // o produto será procurado, se for encontrado sua quantidade será atualizada com a subtração da quantidade informada pelo usuário
            // caso contrário, será informado que o produto não está no estoque
            std::cout << "\tDeseja consultar o estoque antes de prosseguir?" << std::endl;
            std::cout << std::endl;
            std::cout << "\t1. SIM\n";
            std::cout << "\t2. NÃO\n";
            std::cout << std::endl;
            std::cout << "\tDigite uma das opções acima: ";
            std::cin >> opcao_consulta;
            std::cout << std::endl;

            if (opcao_consulta==1)
                EstoqueDaLoja.imprimeEstoque();

            std::cout << "____________________________________________________________\n";
            std::cout << std::endl;
            std::cout << "  Preencha as informacoes abaixo\n";
            std::cout << std::endl;
            std::cout << "\tCÓDIGO DO PRODUTO: ";
            std::cin >> codigo;
            std::cout << "\tQUANTIDADE A RETIRAR DO ESTOQUE: ";
            std::cin >> quantidade;
            std::cout << std::endl;
            std::cout << "____________________________________________________________\n";
            std::cout << std::endl;

            if (EstoqueDaLoja.identificaProduto(codigo))
            {
                EstoqueDaLoja.excluir_produto(codigo, quantidade);
                std::cout << std::endl;
                std::cout << "\tPRODUTO RETIRADO DO ESTOQUE COM SUCESSO!" << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "ATENÇÃO: PRODUTO FORA DE ESTOQUE!" << std::endl;
                std::cout << std::endl;
            }
            break;                     
        }
        case 2:
        {   // o usuário informará um código, que será usado para buscar pelo produto no estoque
            // a partir dele, o programa buscará pelo produto no estoque e o removerá
            std::cout << "\tDeseja consultar o estoque antes de prosseguir?" << std::endl;
            std::cout << std::endl;
            std::cout << "\t1. SIM\n";
            std::cout << "\t2. NÃO\n";
            std::cout << std::endl;
            std::cout << "\tDigite uma das opções acima: ";
            std::cin >> opcao_consulta;

            if (opcao_consulta==1)
                EstoqueDaLoja.imprimeEstoque();

            std::cout << std::endl;
            std::cout << "  INFORME O CÓDIGO DO PRODUTO: ";
            std::cin >> codigo;
            std::cout << std::endl;
            std::cout << "_________________________________________________________________\n";

            if (EstoqueDaLoja.identificaProduto(codigo))
            {
                EstoqueDaLoja.excluir_produto(codigo);
                std::cout << std::endl;
                std::cout << "\tPRODUTO RETIRADO DO ESTOQUE COM SUCESSO!" << std::endl;
                std::cout << std::endl;
            }
            else
                std::cout << std::endl;
                std::cout << "\tATENÇÃO: PRODUTO FORA DE ESTOQUE!" << std::endl;
                std::cout << std::endl;

            break;    
        }
        default:
        {   
            std::cout << "OPÇÃO INVÁLIDA! Selecione uma das opções DO MENU:\n";
            goto menu_excluiProduto;
            break;
        }
    }
}

void Administrador::menuAdm() {
    int opcao = -1;
    std::string op = "";
    while (!getchar()) {            // haverão mais opcoes conforme a necessidade de mais operações
        inicioMenu:
        std::cout << std::endl;
        std::cout << "________________________ MENU DO ADMINISTRADOR _______________________\n";
        std::cout << std::endl;
        std::cout << "\t1) Adicionar produto ao estoque\n";
        std::cout << std::endl;
        std::cout << "\t2) Excluir produto do estoque;\n";
        std::cout << std::endl;
        std::cout << "\t3) Consultar estoque\n";
        std::cout << std::endl;
        std::cout << "\t4) Finalizar sessão\n";
        std::cout << std::endl;
        std::cout << "______________________________________________________________________\n";
        std::cout << std::endl;
        std::cout << "\tSelecione uma opção: ";
        std::cin >> opcao;
        std::cout << std::endl;

        system("clear"); // limpa a tela do terminal

        //  ações a serem executadas de acordo com a escolha do usuario
        try {

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
                excluirProduto();
                std::cout << std::endl;
                break;
            case 3:
                relatorioDeEstoque();
                break;
            case 4:
                std::cout << "Pressione ENTER para encerrar a sessão";
                getchar();
            default:
                std::cout << "Opção invalida! Selecione uma das opções DO MENU\n";
                goto inicioMenu;            // vai para o início do menu
                break;
        }
    }
}
