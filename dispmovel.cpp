#include "dispmovel.h"

DispMovel::DispMovel(int id, double preco, int quantidade, std::string marca, int tela, int ram, int armazenamento):
    Produto(id, preco, quantidade, marca), _tela(tela), _ram(ram), _armazenamento(armazenamento) {}

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
    std::cout << "________________________________________________________________\n";
    std::cout << std::endl;
    std::cout << "CODIGO: " << getID() << std::endl;
    std::cout << "PRECO: R$" << getPreco() << std::endl;
    std::cout << "QUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "MARCA: " << getMarca() << std::endl;
    std::cout << "TAMANHO DA TELA: " << getTela() << " POLEGADAS"<< std::endl;
    std::cout << "MEMORIA RAM: " << getRam() << " GIGABYTES"<< std::endl;
    std::cout << "CAPACIDADE DE ARMAZENAMENTO: " << getArmazenamento() << " GIGABYTES"<< std::endl;
    std::cout << std::endl;    
    std::cout << "________________________________________________________________\n";
}
