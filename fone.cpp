#include "fone.h"

FoneDeOuvido::FoneDeOuvido(int id, double preco, int quantidade, std::string marca, std::string descricao, bool bt, std::string tipo):
    Produto(id, preco, quantidade, marca, descricao), _bt(bt), _tipo(tipo) {}

bool FoneDeOuvido::getBt(){
    return _bt;
}

std::string FoneDeOuvido::getTipo(){
    return _tipo;
}

void FoneDeOuvido::imprimirProduto() {
    std::cout << "______________________________________________________________________\n";
    if (!getEmEstoque())
        std::cout << "\tATENÇÃO: PRODUTO FORA DE ESTOQUE!\n";
    std::cout << std::endl;
    std::cout << "\tCODIGO: " << getID() << std::endl;
    std::cout << "\tDESCRIÇÃO DO PRODUTO: " << getDescricao() << std::endl;
    std::cout << "\tPRECO: R$ " << getPreco() << std::endl;
    std::cout << "\tQUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "\tMARCA: " << getMarca() << std::endl;
    std::cout << "\tTIPO: " << getTipo() << std::endl;
    if (getBt())
        std::cout << "\tCONEXAO BLUETOOTH DISPONIVEL PARA O MODELO" << std::endl;
    else
        std::cout << "\tCONEXAO BLUETOOTH NAO DISPONIVEL PARA O MODELO" << std::endl;
    std::cout << std::endl;    
    std::cout << "______________________________________________________________________\n";
}
