#include <iostream>
#include <string>
#include <vector>

#include "Estoque.h"
#include "produto.h"

int Estoque::indiceDoEstoque = 0;           //inicializando controlador do indice do estoque

void Estoque::adicionar_produto() {
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
    
    Estoque.push_back(p);           // guardando produto criado no estoque teste
    indiceDoEstoque++;              // aumenta sempre que um novo produto é adicionado para mover o indice para posição seguinte

    std::cout << "Produto adicionado ao estoque com sucesso!\n";
}

void Estoque::Relatorio() {
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