#include "televisores.h"

Televisores::Televisores(int id, double preco, int quantidade, std::string marca, std::string descricao, int tela, int resolucao):
    Produto(id, preco, quantidade, marca, descricao), _tela(tela), _resolucao(resolucao) {}

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
    std::cout << "______________________________________________________________________\n";
    if (!getEmEstoque())
        std::cout << "\tATENÇÃO: PRODUTO FORA DE ESTOQUE!\n";
    std::cout << std::endl;
    std::cout << "\tCODIGO: " << getID() << std::endl;
    std::cout << "\tDESCRIÇÃO DO PRODUTO: " << getDescricao() << std::endl;
    std::cout << "\tPRECO: R$" << getPreco() << std::endl;
    std::cout << "\tQUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "\tMARCA: " << getMarca() << std::endl;
    std::cout << "\tTAMANHO DA TELA: " << getTela() << " POLEGADAS"<< std::endl;
    std::cout << "\tRESOLUCAO: " << getResolucao() << " p"<< std::endl;
    std::cout << std::endl;    
    std::cout << "______________________________________________________________________\n";
}
