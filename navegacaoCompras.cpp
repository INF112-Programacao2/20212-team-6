#include<iostream>
#include"navegacaoCompras.h"

NavegacaoCompras::NavegacaoCompras() {}

void NavegacaoCompras::imprimirProdutosDisponiveis()
{
    menu_produtos:
    std::cout << "Bem vindos ao menu de compras\n";
    std::cout << "Selecione uma opção de acordo com o que deseja visualizar\n";
    std::cout << "\t(1) CELULARES\n";
    std::cout << "\t(2) NOTEBOOKS\n";
    std::cout << "\t(3) FONES DE OUVIDO\n";
    std::cout << "\t(4) TELEVISORES\n";
    std::cout << std::endl;

    std::cin >> opc;

    switch(opc)
    {
        case 1:
        {
            listar.imprimeProdutoEmEstoque(10000, 19999);         // exibe de acordo com intervalo referente ao produto
            break;
        }
        case 2:
        {
            listar.imprimeProdutoEmEstoque(20000, 29999);         // exibe de acordo com intervalo referente ao produto
            break;
        }
        case 3:
        {
            listar.imprimeProdutoEmEstoque(30000, 39999);         // exibe de acordo com intervalo referente ao produto
            break;
        }
        case 4:
        {
            listar.imprimeProdutoEmEstoque(40000, 49999);         // exibe de acordo com intervalo referente ao produto
            break;
        }
        default:
        {
            std::cout << "\tOPÇÃO INVÁLIDA! Selecione uma das opções DO MENU: ";
            goto menu_produtos;
            break;
        }
    }
}

void NavegacaoCompras::selecaoDeCompra()
{
    std::cout << "Selecione o produto que deseja comprar:\n";
    std::cout << "Digite o codigo do produto desejado\n"
    cin >> codigo;

    if(listar.identificaProduto(codigo) == false)
        std::cout << "Sinto muito. O produto acabou em nosso estoque mas fiquei de olho que em breve teremos mais!\n"
    
 
}