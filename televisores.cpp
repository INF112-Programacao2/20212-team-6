#include "televisores.h"

Televisores::Televisores(int id, double preco, int quantidade, std::string marca, int tela, int resolucao):
    Produto(id, preco, quantidade, marca), _tela(tela), _resolucao(resolucao) {}

int Televisores::getTela(){
    return _tela;
}

int Televisores::getResolucao(){
    return _resolucao;
}

void Televisores::setTela(int tela){
    _tela = tela;
}

void Televisores::setResolucao(int resolucao){
    _resolucao = resolucao;
}

void Televisores::imprimirProduto() {
    std::cout << "________________________________________________________________\n";
    std::cout << std::endl;
    std::cout << "CODIGO: " << getID() << std::endl;
    std::cout << "PRECO: R$" << getPreco() << std::endl;
    std::cout << "QUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "MARCA: " << getMarca() << std::endl;
    std::cout << "TAMANHO DA TELA: " << getTela() << " POLEGADAS"<< std::endl;
    std::cout << "RESOLUCAO: " << getResolucao() << " p"<< std::endl;
    std::cout << std::endl;    
    std::cout << "________________________________________________________________\n";
}
