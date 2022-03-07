#include <string>
#include <iostream>

#include "usuario.h"
#include "Administrador.h"
#include "Produto.h"
#include "Pedido.h"

int Admin::indiceDoEstoque = 0;           //inicializando controlador do indice do estoque

Admin::Admin(std::string nome, int cpf) : Usuario(nome,cpf) {}

void Admin::adicionarProduto() {
    Produto p;                  // instanciando objeto da classe produto para criar um novo produto

    int codigo;                 // atributos criados localmente para serem repassados ao métodos set do objeto produto
    double preco;
    int quantidade;
    
    std::cout << "Complete as informacoes abaixo para cadastrar o novo produto\n";
    std::cout << "CODIGO: ";
    std::cin >> codigo;
    std::cout << "PRECO: ";
    std::cin >> preco;
    std::cout << "QUANTIDADE: ";
    std::cin >> quantidade;

    p.set_id(codigo);               //repassando dados para o objeto produto criado;
    p.set_preco(preco);
    p.set_quantidade(quantidade);
    
    Estoque[indiceDoEstoque] = p;           // guardando produto criado no estoque teste
    indiceDoEstoque++;                      // aumenta sempre que um novo produto é adicionado para mover o indice para posição seguinte

    std::cout << "Produto adicionado ao estoque com sucesso!\n";
}

void Admin::relatorioDeEstoque() {          // será melhorada quando for feito um estoque mais organizado
    if (indiceDoEstoque == 0) {
        std::cout << "Estoque vazio!" << std::endl;
    }
    else {
        std::cout << "_______ INFORMACOES DO ESTOQUE DA LOJA _______\n" << std::endl;
        for (int i = 0; i < indiceDoEstoque; i++) {
            std::cout << "CODIGO: " << Estoque[i].getID() << std::endl;
            std::cout << "PRECO: " << Estoque[i].getPreco() << std::endl;
            std::cout << "QUANTIDADE: " << Estoque[i].getQuantidade() << std::endl;
        std::cout << "______________________________________________\n";
        }
    }
}

void Admin::menuAdm() {
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
