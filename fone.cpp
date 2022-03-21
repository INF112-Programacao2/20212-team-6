#include "fone.h"

FoneDeOuvido::FoneDeOuvido(int id, double preco, int quantidade, std::string marca, bool bt, std::string tipo):
    Produto(id, preco, quantidade, marca), _bt(bt), _tipo(tipo) {}

bool FoneDeOuvido::getBt(){
    return _bt;
}

std::string FoneDeOuvido::getTipo(){
    return _tipo;
}

void FoneDeOuvido::imprimirProduto() {
    std::cout << "________________________________________________________________\n";
    std::cout << std::endl;
    std::cout << "CODIGO: " << getID() << std::endl;
    std::cout << "PRECO: R$ " << getPreco() << std::endl;
    std::cout << "QUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "MARCA: " << getMarca() << std::endl;
    std::cout << "TIPO: " << getTipo() << std::endl;
    if (getBt())
        std::cout << "CONEXAO BLUETOOTH DISPONIVEL PARA O MODELO" << std::endl;
    else
        std::cout << "CONEXAO BLUETOOTH NAO DISPONIVEL PARA O MODELO" << std::endl;
    std::cout << std::endl;    
    std::cout << "________________________________________________________________\n";
}
