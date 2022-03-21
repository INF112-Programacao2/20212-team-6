#include "notebook.h"

Notebook::Notebook(int id, double preco, int quantidade, std::string marca, int tela, int ram, int armazenamento):
    Produto(id, preco, quantidade, marca), _tela(tela), _ram(ram), _armazenamento(armazenamento) {}

int Notebook::getArmazenamento(){
    return _armazenamento;
}

int Notebook::getRam(){
    return _ram;
}

int Notebook::getTela(){
    return _tela;
}

void Notebook::setArmazenamento(int armazenamento){
    _armazenamento = armazenamento;
}

void Notebook::setRam(int ram){
    _ram = ram;
}

void Notebook::setTela(int tela){
    _tela = tela;
}

void Notebook::imprimirProduto() {
    std::cout << "________________________________________________________________\n";
    std::cout << std::endl;
    std::cout << "CODIGO: " << getID() << std::endl;
    std::cout << "PRECO: R$" << getPreco() << std::endl;
    std::cout << "QUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "MARCA: " << getMarca() << std::endl;
    std::cout << "TAMANHO DA TELA: " << getTela() << " POLEGADAS"<< std::endl;
    std::cout << "MEMORIA RAM: " << getRam() << " GIGABYTES"<< std::endl;
    std::cout << std::endl;    
    std::cout << "________________________________________________________________\n";
}
