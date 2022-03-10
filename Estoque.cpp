#include <iostream>
#include <string>
#include <vector>

#include "Estoque.h"
#include "produto.h"

int Estoque::indiceDoEstoque = 0;           //inicializando controlador do indice do estoque

void Estoque::adicionar_produto() {
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
    std::cout << "MARCA: ";
    std::cin.ignore();
    std::getline(std::cin, marca);
    
    Produto p(codigo, preco, quantidade);                  // instanciando objeto da classe produto para criar um novo produto
    p.setMarca(marca)
    
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
            
        valorTotalDoEstoque += Estoque[i].getPreco() * Estoque[i].getQuantidade(); // calculando valor total do estoque em R$
        }
    }
    std::cout << "Valor total do estoque em reais: R$ " << std::fixed << std::setprecision(2) << valorTotalDoEstoque << std::endl;
}
