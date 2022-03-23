#include <iostream>

#include "dispmovel.h"

DispMovel::DispMovel(int id, double preco, int quantidade, std::string marca, std::string descricao, int tela, int ram, int armazenamento):
    Produto(id, preco, quantidade, marca, descricao), _tela(tela), _ram(ram), _armazenamento(armazenamento) {}

int DispMovel::getArmazenamento(){
    return _armazenamento;
}

int DispMovel::getRam(){
    return _ram;
}

int DispMovel::getTela(){
    return _tela;
}

void DispMovel::setArmazenamento(int armazenamento){
    _armazenamento = armazenamento;
}

void DispMovel::setRam(int ram){
    _ram = ram;
}

void DispMovel::setTela(int tela){
    _tela = tela;
}

void DispMovel::imprimirProduto() {
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
    std::cout << "\tMEMORIA RAM: " << getRam() << " GIGABYTES"<< std::endl;
    std::cout << "\tCAPACIDADE DE ARMAZENAMENTO: " << getArmazenamento() << " GIGABYTES"<< std::endl;
    std::cout << std::endl;    
    std::cout << "______________________________________________________________________\n";
}
